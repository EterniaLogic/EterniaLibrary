#ifndef Inductor_h_
#define Inductor_h_

#include "Component.h"

// An inductor resists change in current; current eventually reaches zero over time.

class Inductor : private Component {
        void tick(SecondTick* tickTime); // operate time
};

#endif
