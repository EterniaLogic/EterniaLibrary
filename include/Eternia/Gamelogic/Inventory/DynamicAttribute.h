//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef DYNAMIC_Attribute_H_
#define DYNAMIC_Attribute_H_


// Bonus types:
enum DynamicAttr {DA_Attack, 
    DA_Armor, DA_Shield, 
    DA_Gunnery, DA_NanoRobots};


// Dynamic Attributes allow for a player, ship parts or weapon to have rare bonuses.

class DynamicAttribute {
    public:
        DynamicAttribute();

        DynamicAttr attrtype;
        double value;
};

#endif
