#ifndef SHIP_H_
#define SHIP_H_

#include "../Location.h"
#include "../../Engineering/Physics/Kinematics/VectorBody.h"

// Ships will not abide by the "lovely" fixed velocity system.
// They will have acceleration in XYZ.

class Ship : public VectorBody {
    public:
        Ship();


        // Location and heading
        vertex sector; // Galaxy sector of this ship
        vertex heading; // Heading of the ship

        VectorBody location; // location of this ship, with applied acceleration


        // Ship parts and modules
};

#endif
