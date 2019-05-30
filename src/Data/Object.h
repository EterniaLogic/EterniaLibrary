#ifndef OBJECT_HH_
#define OBJECT_HH_

#include "Location.h"
#include <iostream>
#include "../Serialization/SpecificSerializer.h"
#include "CharString.h"

class Object : public SpecificSerializer{
public:
    CharString classname, name; // name of the class, useful for debugging non-specific classes.
    Location location; // generic location

    Object(){
        classname = typeid(*this).name(); // class name(?)
        name = "Unknown"; // generic name, can be used for specific objects

        addSerial(&classname, "classname", SSE_CharString);
        addSerial(&name, "name", SSE_CharString);
        addSerial(&location, "location", SSE_SSerializer); // sub-serializer
    }
};

#endif
