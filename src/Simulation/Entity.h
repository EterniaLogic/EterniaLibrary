#ifndef ENTITY_H
#define ENTITY_H

#include "../Data/includes.h"
#include "../Math/Math.h"
#include "Location.h"


// An entity is any being, animal, human, rock, item, etc.
// This class is useful for establishing a baseline for all Simulation types, whether that be intelligent people, assets or even deities.

class Entity{
public:
    CharString name; // common name
    Location location; // location
};



#endif
