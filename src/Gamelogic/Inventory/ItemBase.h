//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef ITEM_BASE_H_
#define ITEM_BASE_H_

#include "../Data/LinkedList.h"
#include "../MiscLib/CharString.h"

// Item base is used to define the very base elements of any item.
//  This may inclue static damage, stats bonuses and other important variables.

class ItemBase
{
    // Static attributes (act as a base for dynamic attributes)
    double sDamage, sDefense, sDodge, sPrice;
    CharString* name, description, craftedBy;
    
    // Dynamic attributes (Dynamic attributes act as special systems, such as levelable weapons)
    LinkedList<DynamicAttribute>* dynamicList;
    
public:
    void init(); // initializes basic item base, use in declaration of item.
};

#endif
