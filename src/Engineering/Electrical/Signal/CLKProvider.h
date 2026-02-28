#ifndef CLKProvider_H
#define CLKProvider_H

#include "Signal.h"
#include <time.h>
#include "../../../Data/LinkedList.hpp"

class CLKModule {
        void (func)();
        int frequency, Counter;
        float timedispersal;
    public:
        CLKModule(int freq);

        void tick();

        // auto-handled function
        void setTimeDispersal(int time);
};


// only use this class; It handles the clock modules.
class CLKProvider {
        LinkedList<CLKModule>* CLKList;
    public:
        CLKProvider();

        // 1 Hz to 100+ MHz
        void setFrequencyEvent(int frequency, void (func)());

        // Automatically figure out of this is the corresponding frequency.
        void tick();
};

#endif
