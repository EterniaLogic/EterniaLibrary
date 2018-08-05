#ifndef TIMER_H_ 
#define TIMER_H_

// Timer class handles real-time timing and scaling time.
// Timer scaling enables other classes or functions to 

// NOTIFY - console message
// FUNCTION - calls timerfunc
enum EVENTTIMER {ET_NONE, ET_NOTIFY, ET_FUNCTION, ET_BOTH};

class Timer{
    double t; // time using double to enable nano-seconds
    
public:
    double timescale = 1.0f; // time multiplier
    double funcrate = 1.0f; // hertz multiplier for function or notify
    EVENTTIMER eventtype = ET_NONE;
    
    Timer(EVENTTIMER event, char* name,  void (*timerfunc)(double time));
    Timer(EVENTTIMER event, char* name);
    virtual ~Timer();
    
    void (*_timerfunc)(double time); // function called. Time is in seconds or fraction of seconds.
    void tick(); // global tick
    void startThread(); // start a gobal thread that runs the tick function
    
    unsigned long getMicroTime(); // returns time in microseconds.
    unsigned long getMilliTime(); // returns time in milliseconds.
    double getTime(); // returns time in seconds. (Direct)
    
    void syncTime(); // sync time with real time
    
    double (*_timemodulo)(double time); // modulate time via a function of your chosing. (normally a null function)
};

#endif
