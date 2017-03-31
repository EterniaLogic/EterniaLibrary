//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef DYNAMIC_Equip_H_
#define DYNAMIC_Equip_H_

#include "ItemBase.h"

class DynamicEquip : public ItemBase {
        DynamicEquip();
        
        double damage; // unique damage
        double defense; // unique defense
        double shield; // unique shield increases
        double dodge; // some gear gives better dodge ability
        double sPrice; // unique item price (Added to base price, used for final NPC price)

        CharString crafter; // crafter name for equipment

        // Dynamic attributes (Dynamic attributes act as special systems, such as levelable weapons)
        // Portable reactors for infantry also have a chance to explode.
        LinkedList<DynamicAttribute> dynamicAttr;
};

#endif
