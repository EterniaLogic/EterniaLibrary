#ifndef TIME_PROFILER_H_
#define TIME_PROFILER_H_

#include "HashMap.hpp"
#include "CharString.h"
#include "CyclicList.hpp"
#include <time.h>

// The time profiler can be used to profile specific items.

class TimeProfiler{
private:
    HashMap<CyclicList<long>> profilemap;
    LinkedList<CharString> items;
    long startTime; // time used when taking a delta
public:
    TimeProfiler();
    virtual ~TimeProfiler();
    
    void beginProfile(); // begin a profiling session
    void endProfile(); // end the profiler, do tallies
    
    void profileItem(CharString name);
    
    void printProfiles(); // prints out all profiles onto console.
};

#endif
