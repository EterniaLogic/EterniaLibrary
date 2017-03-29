//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------


#ifndef SecondTick_h_
#define SecondTick_h_

#include <time.h>

// The SecondTick is used to define a time period for time manipulation. This can be used to slow down time or to speed it up, while defining a frequency at the same time.

// Rates: Frequency = Times/s = Hertz
//        SecondTime = microseconds of how long a second is

class SecondTick {
    public:
        SecondTick(double Frequency, double SecondTime); // Assign vars
        virtual ~SecondTick(); // expire

        SecondTick* clone(); // clone this

        double getFrequency(); // return frequency
        double getSecondTime(); // return secondTime
        double getTime(); // return tick time expired in microseconds = time/Freq
        double getTrueTime(); // return tick time expired in microsends time();

        void setRealTime(bool use); // set getTime() to realtime if true

    private:
        double frequency;
        double secondTime;
        double lastTT; // last time(); used
        bool useTrue;
};

#endif
