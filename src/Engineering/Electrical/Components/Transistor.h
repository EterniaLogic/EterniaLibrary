#ifndef TRANSISTOR_h_
#define TRANSISTOR_h_

#include "Component.h"

// A transistor is useful for amplification and signal switching

class Transistor : private Component {
    public:
        Transistor();
        virtual ~Transistor();

        void tick(SecondTick* tickTime); // operate time

    private:
        // pinB (declared in component) used as Base
        PowerValue* pinG; // Gate Pin
        PowerValue* pinD; // Drain pin
};

#endif
