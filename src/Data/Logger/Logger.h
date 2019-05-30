#ifndef LOGGER_H_
#define LOGGER_H_

#include "../CharString.h"
#include "../Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include <chrono>


#include <thread>


class Logger{
private:
    std::thread asyncthread;
    std::ofstream file;
public:
    Logger(CharString logfileloc, CharString prefix, bool async, bool console, bool clearfile); // if ASYNC, start thread
    Logger(); // Runs basic properties, unknown values?
    
    virtual ~Logger(); // if ASYNC, stop thread
    
    void Log(CharString data);
    void log(CharString data); // same
    
    void processLog(CharString data);
    bool handleLogs(); // internal Async command, writes to file
    
    Logger& operator=(const Logger&);
    
    
    CharString logfileloc, prefix;
    bool async, console, ending;
    Queue asyncLog;
    
    static Logger GLOBAL, ERROR;
};

#endif
