//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Physics_Equations_h
#define Physics_Equations_h

#include "../../constants.h"

// general physics equation solvers
class PhysicsEquations {
public:
        //                      m/s**2          meters          kilograms
        static double getAirPressure(double gravity, double radius, double atmosMass); // Get P0 at sea level based on information
        static double getGravity(double mass1, double mass2, double radius); // Gravity of an object with respect to another object (m/s**2)
        
        static double calcSTDGrav(double mass1, double mass2); // calculates standard gravity parameter, Mu = G*(m1*m2)
        
        // REF: view-source:http://files.arklyffe.com/orbcalc.html
};

#endif
