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
        //                      m/s**2          meters          kilograms
        double getAirPressure(double gravity, double radius, double atmosMass); // Get P0 at sea level based on information
        double getGravity(double mass1, double mass2, double radius); // Gravity of an object with respect to another object (m/s**2)
};

#endif
