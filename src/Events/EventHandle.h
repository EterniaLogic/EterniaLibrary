#ifndef EVENTHANDLE_H_
#define EVENTHANDLE_H_

#include <time.h>
// The Event Handler is an API that allows use and execution of set events
//      These events can include window draws, physics, mouse clicks, ect.

class EventHandle{
private:
        void (*method)(); // variable method
        void (*method1)(void* arg);
        void (*method2)(void* arg, void* arg2);
        int recurring; // always run?
        long timex, timediff;
        
public:
        EventHandle(void (*func)()); // event to handle
        EventHandle(void (*func)(void* arg)); // event to handle
        EventHandle(void (*func)(void* arg, void* arg2)); // event to handle
        ~EventHandle();
        
        void init();
        
        // void (*func)() = (void (*)())current->data;
        bool handle(); // handle this event
        void setRecurrences(int recurs);
        void setRecurForever(); // recur forever... and ever... and ever
        
        void setPeriod(long periodlen); // set the time period for occurence in ms (precedes recurring)
        
        void *arg1, *arg2;
};

#endif
