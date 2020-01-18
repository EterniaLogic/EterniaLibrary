#ifndef HBridge_h_
#define HBridge_h_

#include "Component.h"

// An H-Bridge is a device that allows current to run in either direction for a motor.

class HBridge : private Component {
    public:
        HBridge();
        virtual ~HBridge();

        void tick(SecondTick* tickTime); // operate time
};

#endif
