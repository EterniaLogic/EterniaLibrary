#include "Logger.h"

void loggerThread(Logger* logger){
    long ticks_per_sec, time, last;
    
    while(true){
        last = clock();
        
        // handle logs
        if(!logger->handleLogs()) break;
        
        ticks_per_sec = 10.0;
        time = (1000000.0/ticks_per_sec) - (((clock()-last)*1000000.0)/CLOCKS_PER_SEC);
        if(time > 0) std::this_thread::sleep_for(std::chrono::microseconds(time));
    }
}


// if ASYNC, start thread
Logger::Logger(CharString logfileloc, CharString prefix, bool async, bool console){
    this->logfileloc = logfileloc;
    this->prefix = prefix;
    this->async = async;
    this->console = console;
    
    // open file
    
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
}

void Logger::Log(CharString data){
    // combine data with prefix, timestamp.
    data.concatb(prefix);
    
    // async
    if(async){
        // save for the thread
        //asyncLog.push(data);
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
}

bool Logger::handleLogs(){
    // asyncLog
    CharString* str;
    
    while((str = (CharString*)asyncLog.pop()) != 0x0){
        processLog(*str);
    }
    
    return (!ending);
}
