//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Collision1D.h"

Collision1D::Collision1D()
{
}

// gets the resultant velocity of purely inelastic collision.
double Collision1D::getPurelyInelasticVelo(){
    double ret = 0;
    
    // v = (mava + mbvb)/(ma + mb)
    ret = (a1->mass * a1->velocity + b1->mass * b1->velocity) / (a1->mass + b1->mass);
    
    return ret;
}

// assumes that this is not purely inelastic
// returns double[2]
double* Collision1D::getVelo(){
    double* ret = new double[2];
    
    double m1 = a1->mass;
    double m2 = b1->mass;
    double m1m2 = m1+m2;
    double v = a1->velocity - b1->velocity;
    
    double V1final = ((m1-m2)/(m1m2))*v;
    double V2final =  ((2*m1)/(m1m2))*v;
    ret[0] = V1final;
    ret[1] = V2final;
    
    return ret;
}
