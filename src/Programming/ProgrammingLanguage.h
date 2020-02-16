#ifndef PROG_LANG_H_
#define PROG_LANG_H_

#include "../Data/includes.h"

// Base of multiple scripting/visual languages
//  - Multi-threadable

class ProgrammingLanguage{
public:
	virtual ~ProgrammingLanguage(){}

    virtual void main(LinkedList<CharString> args); // startup
    virtual void tick(double timeseconds); // tick loop, time difference is given by user (limited by run_thread or runtick to prevent infinite loops maxing CPU)
    
    // Standard
    virtual void loadScript(CharString filedata); // load script from file, if main or loop functions, then overwrite (Does not remove loaded globals/functions)
    
    
    // API
    // Global Variables
    virtual void setVar(CharString varname, DynamicType vardata);
    virtual DynamicType getVar(CharString varname);
    
    virtual DynamicType runFunction(CharString funcname, LinkedList<DynamicType> args); // run a function on the same thread, maximum scripting speed
    

    // Control
    virtual void runtick(); // tick the lower layer of the language or nodes ONCE, manually controlling the loop rate so infinite loops do not slow down the machine.
    virtual void run_thread(double seconds); // tick the entire language at the number of seconds (20Hz is 0.05 seconds, 1 MHz is 1.0e-9 seconds, 1 GHz is 1.0e-12 seconds)

};

#endif
