#include "Logger.h"

using namespace std;

void loggerThread(Logger* logger){
    long ticks_per_sec, time, last;
    
    while(true){
        last = clock();
        
        // handle logs
        if(!logger->handleLogs()) break;
        
        ticks_per_sec = 5.0;
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
    
    // open file
    if(clearfile) file.open (logfileloc.get(), ios::out | ios::app);
    else file.open (logfileloc.get(), ios::out | ios::app | ios::trunc);
    file.seekp(0, ios::end);
    
    if(async){
        asyncthread = std::thread(loggerThread, this);
    }
}


Logger::~Logger(){
    // flush the file, close it

    if(async){
        // stop thread
        ending=true;
        asyncthread.join();
    }
    
    file.close();
}

void Logger::Log(CharString data){
    // combine data with prefix, timestamp.
    data.concatb(prefix);
    
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

void Logger::processLog(CharString data){
    if(console){
        cout << data.get() << endl;
        cout.flush();
    }
    
    // push data to file
    if(file.is_open()){
        file.write(data.get(), data.getSize());
        file.write((char*)"\r\n", 2);
    }
}

bool Logger::handleLogs(){
    // asyncLog
    CharString* str;
    
    while((str = (CharString*)asyncLog.pop()) != 0x0){
        processLog(*str);
    }
    
    return (!ending);
}
