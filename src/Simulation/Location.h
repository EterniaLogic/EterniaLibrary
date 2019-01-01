#ifndef LOCATION_H_
#define LOCATION_H_

#include "../Data/includes.h"
#include "../Math/Math.h"

class Location : public SpecificSerializer {
    public:
        Location(vertex sector, VertexObject local);
        Location();

        // Location (two values to allow for 32-bit)
        vertex sector; // sector quadrant
        
        // Local location enables XYZ, velocity and acceleration
        VertexObject local; // local area (by local, solar-system wide)
};

#endif
