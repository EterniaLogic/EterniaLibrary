#ifndef cENTITY_H
#define cENTITY_H

#include "../Data/includes.h"
#include "../Math/Math.h"
#include "Location.h"
#include "Object.h"
#include "Action.h"

// An entity is any being, animal, human, rock, item, etc.
// This class is useful for establishing a baseline for all Simulation types, whether that be intelligent people, assets or even deities.




class CEntity : public Object{
public:
    CharString name; // common name
    // Location location; (inherrited from Object)
    CEntity();
    
    bool onaction(Action act); // called before any action, sent to mods or w/e handlers.
};



#endif
