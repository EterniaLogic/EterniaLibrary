//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef ITEM_BASE_H_
#define ITEM_BASE_H_

//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "../../Data/LinkedList.hpp"
#include "../../MiscLib/CharString.h"
#include "DynamicAttribute.h"

// Item base is used to define the very base elements of any item.
//  This may inclue static damage, stats bonuses and other important variables.

class ItemBase
{   
public:
    void init(); // initializes basic item base, use in declaration of item.
    
private:
    // Static attributes (act as a base for dynamic attributes)
    int max_stack; // maximum stackable (gear is normally 0, not stackable)
    double sDamage;
    double sDefense;
    double sDodge;
    double sPrice;
    CharString* name;
    CharString* description; // description of the item
    CharString* crafter; // generic crafter name, can be queried
    
    // Dynamic attributes (Dynamic attributes act as special systems, such as levelable weapons)
    LinkedList<DynamicAttribute>* dynamicList;
};

#endif
