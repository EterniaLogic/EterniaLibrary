
#ifndef PIN_H
#define PIN_H


#include "../../Data/CharString.h"
#include "PowerValue.h"

class Pin {
        CharString* name;
        PowerValue* val;
    public:
        Pin(CharString* PinName, PowerValue* value);
        virtual ~Pin();

        void setValue(PowerValue* value);
        PowerValue* getValue();

        CharString* getName();
};

#endif
