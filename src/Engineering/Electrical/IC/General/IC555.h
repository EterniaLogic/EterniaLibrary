
#ifndef IC555_h_
#define IC555_h_

#include "../IC.h"

// The 555 is often used as a pulse driver

class IC555 : private virtual IC {
    public:
        IC555();
        virtual ~IC555();

        virtual double getPin(int pin); // return the value on a specific pin
        virtual void setPin(int pin, double value); // set the value on a pin

        virtual void tick(SecondTick* tickTime); // operate the component
};

#endif
