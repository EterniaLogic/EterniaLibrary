#ifndef SLOCATION_H_
#define SLOCATION_H_

#include "../Data/Location.h"
#include "../Math/Math.h"

using namespace Math;

class SLocation : public Location {
public:
    SLocation(vertex sector, VertexObject local);
    
    vertex sector; // sector quadrant (For scifi/space simulations only)
    
    
    // Local location enables XYZ, velocity and acceleration.
    // For scifi simulations, this would be on a planet or something.
    // VertexObject enables this object to have gravity pull if in a space.
    
    // If only used on the ground in a planet, just use local as a normal location XYZ.
    VertexObject local; // local area (by local, solar-system wide)
};
