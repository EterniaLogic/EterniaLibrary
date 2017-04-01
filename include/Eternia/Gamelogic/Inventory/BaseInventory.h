//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef BaseInventory_h_
#define BaseInventory_h_

#include "../../Data/LinkedList.hpp"
#include "ItemBase.h"
#include "../../Serialization/SpecificSerializer.h" // Serializer for saving data

class BaseInventory : public SpecificSerializer {
public:
    BaseInventory();
private:
    LinkedList<ItemBase> inventoryItems;
    int maxslots; // max slots in this bag
};

#endif
