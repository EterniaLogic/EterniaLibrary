#ifndef BUILDING_H_
#define BUILDING_H_

#include "../../Serialization/SpecificSerializer.h"

// Buildings may have multiple parts to them.
//  The verticies required to draw them are still combined on render, but this allows for modular parts.

// A good example of a multi-part building is a defense turret. The bottom is for the hardpoint, while
//  the top part is the actual weapon on a swivel system.

class Building : public SpecificSerializer {
public:
    Building(); // Code to set up a building. This is still executed even in a polymorphism case.
    virtual ~Building();
};


#endif // BUILDING_H_
