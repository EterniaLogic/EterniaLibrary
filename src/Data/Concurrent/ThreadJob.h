#ifndef THREADJOB_H_
#define THREADJOB_H_

#include "../CharString.h"
#include <time.h>
#include <chrono>
#include <future>         // std::async, std::future
#include <functional>
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

// All job functions have a bool *running as the first argument for nicely stopping while loops.

/*  void ClassT::testfunc(bool *running, CharString text){
        while(*running){
            ...
        }
    }   */

class ThreadJobBase{ // enables jobs without requiring templates
public:
    CharString jobname;
    bool done;
    bool running;
    
    void _run(){
        run(); // avoid template?
    }

    virtual void run(){cout << "threadjobbase no run() used" << endl;} // in ThreadJob
};

//template<class Function, class ClassT, class... Args>
class ThreadJob : public ThreadJobBase{
public:
    //std::function<typename std::result_of<Function>::type> func; // future function value
    //std::function<typename std::result_of<Function>::type> func;
    /*void (* func)(class... args);
    void* classt;
    std::tuple<class...> args;*/
    
    void (*func)();
    
    //std::future<void> funcfuture;
    
    //ThreadJob(CharString name, Function&& f); // void function(bool *running){}
    //ThreadJob(CharString name, Function&& f, ClassT *classt); // void ClassT::function(bool *running){}
    //ThreadJob(CharString name, Function&& f, ClassT *classt, Args&&... args); // void ClassT::function(bool *running, int arg, bool arg2){}
    
    // void ClassT::function(bool *running, int arg, bool arg2){}
    ThreadJob(CharString name, void (*f)()){
        this->jobname = name;
        this->done = false;
        this->running = false;
        
        func = f;
        
        /*args = std::tuple<class...>(args...);
        classt = classt;
        func = f;*/
        //func = std::bind(f, classt, &running, args...);
    }

    // void ClassT::function(bool *running){}
    /*ThreadJob(CharString name, Function&& f, ClassT *classt){
        this->jobname = name;
        this->done = false;
        this->running = false;
        
        func = std::bind(f, *classt, &running);
    }*/

    // void function(bool *running){}
    /*ThreadJob(CharString name, void* f ){ // Function&& f
        this->jobname = name;
        this->done = false;
        this->running = false;
        
        //func = std::bind(f, &running);
        func = f;
    }*/
    
    void run(){ // run on this thread
        // ?
        this->running = true;
        //this->func(argsx);
        this->func();
        this->done = true;
    }
};

#endif
