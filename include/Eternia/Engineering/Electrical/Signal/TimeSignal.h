//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef TimeSignal_H_
#define TimeSignal_H_

#include "../Data/LinkedList.hpp"
#include "FreqSignal.h"

class TimeSample {
public:
    float value;
    float time; // time displacement in seconds.
};


// A time signal is a sampled signal from either a digital source
//      or an analog source.

// An fft can get the frequency domain.
class TimeSignal {
private:
    LinkedList<Sample> samples;
public:
    TimeSignal();
    virtual ~TimeSignal();

    // time constants and delays are factored in these functions
    void sampleDigital(boolean value, float time); // sample a digital signal (0->1f)
    void sampleAnalog(float value, float time); // sample an analog signal (-1f -> 1f)
    
    // sample in real-time
    void startSample(); // sets up time offset
    void sampleDigital(boolean value); // sample a digital signal (0->1f)
    void sampleAnalog(float value); // sample an analog signal (-1f -> 1f)
    
    void clearSamples();

    // math functions
    void amplify(float value);

    FreqSignal FFT(); // outputs the frequency domain, useful to apply filters
};

#endif
