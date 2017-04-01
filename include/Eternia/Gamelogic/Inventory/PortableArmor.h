#ifndef PORTABLE_ARMOR_H
#define PORTABLE_ARMOR_H

#include "DynamicEquip.h"

#ifndef Avatar_h_
#include "../Avatar/Avatar.h"
#else
class Avatar;
#endif

// Portable Armor is a mecha suit

// Mecha suits can be templated for infantry.


// The general idea behind these suits is not for "Armor" protection, but for
//  enhanced shielding.

class PortableArmor {
    public:
        PortableArmor();

        DynamicEquip helmet; // main visor helmet
        DynamicEquip left_arm;
        DynamicEquip right_arm;
        DynamicEquip torso;
        DynamicEquip leggings;
        DynamicEquip left_foot;
        DynamicEquip right_foot;

        // Specific items:
        DynamicEquip reactor_core; // Specific reactor type (fuel, nuclear, anti-matter)
        DynamicEquip reactor_cooling; // Cooling system for reactor

};

#endif
