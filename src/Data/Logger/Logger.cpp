#include "Logger.h"

using namespace std;

Logger Logger::GLOBAL("global.log", "[GLOBAL]", true, true, true);
//Logger Logger::SERVER("server.log", "[SERVER]", true, true, true);
//Logger Logger::CLIENT("client.log", "[CLIENT]", true, true, true);
Logger Logger::ERROR("error.log", "[ERROR]", true, true, true);

void loggerThread(Logger* logger){
    long ticks_per_sec, time, last;
    cout << "logger thread start : " << logger->prefix << "    " << logger->logfileloc << endl;
    while(!logger->ending){
        last = clock();


        // handle logs
        logger->handleLogs();

        ticks_per_sec = 50.0;
        time = (1000000.0/ticks_per_sec) - (((clock()-last)*1000000.0)/CLOCKS_PER_SEC);
        if(time > 0) std::this_thread::sleep_for(std::chrono::microseconds(time));
    }
}


// if ASYNC, start thread
Logger::Logger(CharString logfileloc, CharString prefix, bool async, bool console, bool clearfile){
    this->logfileloc = logfileloc;
    this->prefix = prefix;
    this->async = async;
    this->console = console;
    this->ending = false;
    //cout << "Logger(,,,,)" << endl;
    //cout << "Logger 1" << endl;
    // open file
    if(clearfile) file.open (logfileloc.get(), ios::out | ios::app);
    else file.open (logfileloc.get(), ios::out | ios::app | ios::trunc);
    opened=true; // file opened
    file.seekp(0, ios::end);

    //cout << "Logger 2" << endl;

    if(async){
        asyncthread = std::thread(loggerThread, this);
        //cout << "Logger 3thrstart" << endl;
    }
    //cout << "Logger(,,,,) end" << endl;
    //cout << "Logger 3" << endl;
}

Logger::Logger(){
 //???
	async=false;
	ending=false;
	console=false;
    opened=false;
    //cout << "Logger basic start" << endl;
}


Logger::~Logger(){
    if(async){
        // stop thread
        ending=true;
        if(asyncthread.joinable()){
            asyncthread.join(); // force if able
        }
    }

    if(opened){
        if(file.is_open()){
            file.close();
        }
    }
}

void Logger::Log(CharString data){
    // combine data with prefix, timestamp.
    data.concatb(prefix);
    data.concatb(CS_NL);

    // async
    if(async){
        // save for the thread
        CharString* cc = new CharString();
        *cc = data;
        asyncLog.push(cc);
    }else{
        processLog(data);
    }
}

void Logger::log(CharString data){
    Log(data);
}

void Logger::processLog(CharString data){
    if(console){
        cout << data;// << endl;
        cout.flush();
    }

    if(!file.is_open()){
        file.open(logfileloc.get(), ios::out | ios::app);
    }

    // push data to file
    if(file.is_open()){
        file.write(data.get(), data.getSize());
        file.write((char*)"\n", 1);
    }else{
        cout << "file not open..." << endl;
    }
}

bool Logger::handleLogs(){
    // asyncLog
    CharString* str;
    //cout << "handleLogs 1" << endl;

    while((str = (CharString*)asyncLog.pop()) != 0x0){
        //cout << "handleLogs 2" << endl;
        processLog(*str);
    }

    //cout << "handleLogs 3" << endl;

    return (!ending);
}

Logger& Logger::operator=(const Logger& l){
    this->logfileloc = l.logfileloc;
    this->prefix = l.prefix;
    this->async = l.async;
    this->console = l.console;
    this->ending = false;

    l.~Logger();

    // open file
    //if(clearfile) file.open (logfileloc.get(), ios::out | ios::app);
    //else
    file.open (logfileloc.get(), ios::out | ios::app | ios::trunc);
    file.seekp(0, ios::end);

    this->ending = false; // reset ending
    asyncthread = std::thread(loggerThread, this);
}
