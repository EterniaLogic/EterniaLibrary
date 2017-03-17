#ifndef LOGGER_H_
#define LOGGER_H_

#include "../CharString.h"
#include "../Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

class Logger{
private:
    CharString logfileloc, prefix;
    bool async, console, ending;
    Queue asyncLog;
    std::thread asyncthread;
    
    std::ofstream file;

public:
    Logger(CharString logfileloc, CharString prefix, bool async, bool console, bool clearfile); // if ASYNC, start thread
    virtual ~Logger(); // if ASYNC, stop thread
    
    void Log(CharString data);
    
    void processLog(CharString data);
    bool handleLogs(); // internal Async command, writes to file
};

#endif
