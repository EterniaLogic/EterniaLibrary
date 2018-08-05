

#include "Equations.h"

// Air pressure at sea level. (N/m**2)
double PhysicsEquations::getAirPressure(double gravity, double radius, double atmosMass) {
    // Pressure = F/A
    // Force = AtmosMass * Gravity
    // Area = 4*pi*r^2
    double area = 4 * physical::unit::pi *radius*radius;
    double force = atmosMass * gravity;
    return force / area;
}

// Gravity of an object with respect to another object (m/s**2)
double PhysicsEquations::getGravity(double bigMass, double radius) {
    // Gravity = G * ((m1 * m2)/(r^2))
    return physical::constant::G * (bigMass/* * mass2*/) / (radius*radius);
}
