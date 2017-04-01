#ifndef COMPONENT_h_
#define COMPONENT_h_

#include "../PowerValue.h"
#include "../../../Emulation/SecondTick.h"
#include "ComponentRating.h"

// general component class

class Component {
    public:
        PowerValue* getPinA(); // Returns the pin A
        PowerValue* getPinB(); // Returns the pin B

        void tick(SecondTick* tickTime); // operate the component


    private:
        PowerValue* pinA; // normally the Input
        PowerValue* pinB; // normally the Output

        ComponentRating* rating; // used for basic components, ICs may have multiple ratings due to the pins.
};

#endif
