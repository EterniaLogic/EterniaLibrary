//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Equations.h"

// Air pressure at sea level. (N/m**2)
float PhysicsEquations::getAirPressure(float gravity, float radius, float atmosMass){
    // Pressure = F/A
    // Force = AtmosMass * Gravity
    // Area = 4*pi*r^2
    float area = 4 * physical::unit::pi *radius*radius;
    float force = atmosMass * gravity;
    return force / area;
}

// Gravity of an object with respect to another object (m/s**2)
float PhysicsEquations::getGravity(float mass1, float mass2, float radius){
    // Gravity = G * ((m1 * m2)/(r^2))
    return physical::constant::G * (mass1 * mass2) / (radius*radius);
}
