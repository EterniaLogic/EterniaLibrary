#ifndef ROLLER_H_
#define ROLLER_H_

#include "Workshop.h"

class RollingMachine : public Workshop{
public:

    RollingMachine(){
        classname="RollingMachine";
        // standard rolling
        recipes.add(new Recipe("Metal Ingot, NOCONSUME Plane Roller", "Metal Plate", 900));
        recipes.add(new Recipe("Metal Plate, NOCONSUME Plane Roller", "Metal Foil", 500));
        
        // wire rolling
        recipes.add(new Recipe("Metal Plate, NOCONSUME Wire Roller, NOCONSUME drawplate",  "Metal Wire", 2000)); // second option, using diamond-shaped wire grooves in rolling machine, then using drawplate to cylindrize the wire
    }
};

#endif
