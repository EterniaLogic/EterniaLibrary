#ifndef Physics_Equations_h
#define Physics_Equations_h

#include "../../constants.h"

// general physics equation solvers
class PhysicsEquations {
public:
        //                      m/s**2          meters          kilograms
        static double getAirPressure(double gravity, double radius, double atmosMass); // Get P0 at sea level based on information
        static double getGravity(double bigmass, double radius); // Gravity of an object with respect to another object (m/s**2)
        
        static double calcSTDGrav(double mass1, double mass2); // calculates standard gravity parameter, Mu = G*(m1*m2)
        
        // REF: view-source:http://files.arklyffe.com/orbcalc.html
};

#endif
