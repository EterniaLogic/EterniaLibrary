
#ifndef IC_h_
#define IC_h_

#include "../Components/Component.h"
#include "../../../Data/LinkedList.hpp"
#include "../Pin.h"

// Defines basic Integrated Circuit

class IC : private virtual Component {
    public:
        void setPins(LinkedList<Pin*> list); // set the initial pins list
        int getMaxPins();

        Pin* getPin(int pin); // return the value on a specific pin

        void setPin(int pin, Pin* value); // set the value on a pin



        void tick(SecondTick* tickTime); // operate the component
//protected:
        LinkedList<Pin*> pins;
        int maxPins;
};

#endif
