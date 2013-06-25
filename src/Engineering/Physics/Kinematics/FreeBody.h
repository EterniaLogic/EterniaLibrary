//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef FREEBODY_H_
#define FREEBODY_H_

#include "../../../constants.h"
#include "../../../Data/LinkedListT.h"
#include "VectorBody.h"
#include "../../../Math/Equation.h"

using namespace physical;
using namespace physical::constant;

// converts KItem to a string
CharString* getVariableFromKItem(KItem item);

// Freebody diagram, automatic inter-sourcing of data.
// Used to solve Kinematic problems

class FreeBody;

class Force
{
public:
    Force();
    KItem* force; // type of force
    double quantity; // quantity of force
    KDirection* direction; // direction of force
    Equation* equation;
    
    
    bool directionNegative; // is the direction on the opposite side?
    
    // tied item when using T for Tension.
    FreeBody* tiedItem;
};

class FreeBody : public VectorBody
{
    LinkedListT *forceList;
    
    bool hasItemType(KItem item);
    public:
        FreeBody();
        void addItem(KItem item, double quantity); // KForce in constants.h defines a set of kinematic forces that can be used.
        double getProperty(KItem item); // get a specific property of this element. (Returns -99999 if not found)
};

#endif /*FREEBODY_H_*/
