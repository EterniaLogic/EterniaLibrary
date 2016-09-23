//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "FreeBody.h"


Force::Force(){force=0x0; quantity=0; direction = 0x0; equation=0x0; directionNegative=false; tiedItem = 0x0;}
FreeBody::FreeBody(){ forceList = new LinkedListT(); }


// add a force to the system.
void FreeBody::addItem(KItem item, double quantity){
    // Forces can be anything, albiet Gravity all the way to direct Newton force.
    // for now, we will only add it to the list to be calculated later.
    CharString* fromEq = getVariableFromKItem(&item);
    Force* f = new Force();
    f->force = &item;
    f->quantity = quantity;
    f->equation = new Equation(fromEq);
    forceList->add(f);
}

bool FreeBody::hasItemType(KItem item){
    for(int i=0; i<forceList->frozenlen ; i++){
        if(item == *(((Force*)forceList->frozen[i])->force)){
            return true;
        }
    }
    return false;
}

// [Kinematics 101]
//  #2  vf^2 = vi^2 + 2*a*d   << 2 velos, find accel or distance
//  #3  vf = vi + a*t         << 1-Dim equation.
//  #4  d = t*((vi + vf)/2)   << 2 velos and time, get distance
//
// [Circular motion]
//  #5  (mv^2)/2
//
// [Friction]
// #6   Ff = Mu * N
double FreeBody::getProperty(KItem item){
    // gets known variables and attempts to plug them into an equation that fits.
    //bool hasAcceleration = false, hasVelocity = false, hasDistance = false, hasForce = false, hasTime = false, hasGravity = false, hasFriction = false,
    //    hasCentripetal = false, hasFrictionCoefficient = false, hasTension = false, hasNormal = false;
        
    // capture a frozen segment of forceList.
    forceList->freeze();
    
    if(hasItemType(KTime) || item == KTime){
        // #'s 3, 4
        if(item == KDistance){}
        else if(item == Kxf){}
        else if(item == Kxi){}
        else if(item == KVelocity){}
        else if(item == KVelocityFinal){}
        else if(item == KTime){}
    }else{
        // #'s 2, 5, 6
        if(item == KDistance){}
        else if(item == Kxf){}
        else if(item == Kxi){}
        else if(item == KVelocity){}
        else if(item == KVelocityFinal){}
        else if(item == KTime){}
    }


	return 0;
}

//  #1  d=vi*t + 0.5*a*t^2    << Projectile
double getProjectileProperty(KItem& item){
    // solve for each form.
    Equation* e1 = new Equation(new CharString("xf-xi = vi*t + 0.5*a*t^2",24));
    // KDistance = xf-xi



	return 0;
}
