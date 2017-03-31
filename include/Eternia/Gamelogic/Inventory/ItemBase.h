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
#include "../../Data/CharString.h"
#include "DynamicAttribute.h"

// Item base is used to define the very base elements of any item.
//  This may inclue static damage, stats bonuses and other important variables.

class ItemBase {
public:
    void init(int id, int stacksize, double price); // initializes basic item base, use in declaration of item.

private:
    // Static attributes (act as a base for dynamic attributes)

    CharString* name; // basic name of this item.
    CharString* description; // description of the item.
    int id; // base item id, useful for net transfer ids.
    int stacksize; // number of items in this stack.
    double price; // Base price for this item.
};

#endif
