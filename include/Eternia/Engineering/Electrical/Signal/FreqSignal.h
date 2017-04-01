//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef FreqSignal_H_
#define FreqSignal_H_

#include "TimeSample.h"

// Frequency domain, use ifft to get time domain...
//  Time in this case is actually the frequency range.
class FreqSignal {
private:
    LinkedList<Sample> samples;
public:
    FreqSignal();
    virtual ~FreqSignal();

    // filter the samples, auto-calculates a filter based on inputs
    // dbm determines how fast it will drop
    void bandpassFilter(float centerFreq, float dbm); 
    void lowpassFilter(float centerFreq, float dbm);
    void highpassFilter(float centerFreq, float dbm);
    void notchFilter(float centerFreq, float dbm);
    
    FreqSignal noiseProfile(); // gets the profile for noise (use static ambient)
    void noiseFilter(FreqSignal profile, float dbm); // appends that filter

    TimeSignal IFFT(); // outputs the time domain
};

#endif
