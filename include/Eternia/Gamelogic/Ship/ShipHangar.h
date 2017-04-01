#ifndef SHIPHANGAR_H_
#define SHIPHANGAR_H_

#ifndef SHIP_H_
#include "Ship.h"
#else
class Ship;
#endif

#include "../../Data/LinkedList.hpp"

// Ship hangars hold... well ships

class ShipHangar {
    public:
        ShipHangar();

        // ships currently stored in the hangar.
        LinkedList<Ship> ships();
};

#endif
