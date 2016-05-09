#include "EventHandle.h"


//#define DEBUG_EHx

#ifdef DEBUG_EHx
#define debugLogEHx(ehs) cout << ehs << endl;
#else
#define debugLogEHx(ehs)
#endif

#include <iostream> // testing purposes only
using namespace std;

void EventHandle::init(){
        this->method=0x0;
        this->method1=0x0;
        this->method2=0x0;
        this->arg1 = this->arg2 = 0x0;
        this->recurring = 0; // only happens once
        this->timex = 0;
        this->timediff = 0;
}


EventHandle::EventHandle(void (*func)()){
        init();
        this->method = func;
}

EventHandle::EventHandle(void (*func)(void* arg)){
        init();
        this->method1 = func;
}

EventHandle::EventHandle(void (*func)(void* arg, void* arg1)){
        init();
        this->method2 = func;
}


// handle the event, returns false if it is not recurring anymore
bool EventHandle::handle(){
        debugLogEHx("EH 0");
        if(this->method == 0x0 && this->method1==0x0 && this->method2==0x0) return false; // no method

        debugLogEHx("EH 1");
        // timed occurence (prevents action until >= current time
        if(timediff > 0){
                if(this->timex >= ((1000*clock())/CLOCKS_PER_SEC)){
                        return true;// has not occured yet
                }else{
                        // occured! Reset timer
                        timex = ((1000*clock())/CLOCKS_PER_SEC) + timediff;
                }
        }
        debugLogEHx("EH 2");
        // get the function and execute it.

        void (*func)() = this->method;
        void (*func1)(void*) = this->method1;
        void (*func2)(void*,void*) = this->method2;
        if(func != 0x0) func();
        if(func1 != 0x0) { func1(arg1); }
        if(func2 != 0x0) func2(arg1,arg2);

        debugLogEHx("EH 3");

        if(recurring == -1){ // recur forever and ever~
                return true;
        } else if(recurring > 0){
                recurring--;
                return true;
        }

        debugLogEHx("EH 4");

        return false;
}

// set to allow recurring
//      Input:
//              int recurs    ::    how many times to recur?
void EventHandle::setRecurrences(int recurs){
        recurring = recurs-1;
}

// recur forever... and ever... and ever
void EventHandle::setRecurForever(){
        recurring = -1;
}

// set the time period for occurence in ms (precedes recurring)
void EventHandle::setPeriod(long periodlen){
        timediff = periodlen;
        timex = ((1000*clock())/CLOCKS_PER_SEC) + periodlen;
}
