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

class Sample {
        bool digital;
        float value;
        float time; // time displacement
};


// A time signal is a sampled signal from either a digital source
//      or an analog source.
class TimeSignal {
        LinkedList<Sample>* samples;
    public:
        TimeSignal();

        // time constants and delays are factored in these functions
        void sampleDigital(boolean value); // sample a digital signal
        void sampleAnalog(float value); // sample an analog signal

        // math functions
        TimeSignal* subtract(TimeSignal* signal);
        TimeSignal* add(TimeSignal* signal);
        TimeSignal* multiply(TimeSignal* signal);
        TimeSignal* divide(TimeSignal* signal);

        FreqSignal* FFT(); // outputs raw FFT frequency domain
};

#endif
