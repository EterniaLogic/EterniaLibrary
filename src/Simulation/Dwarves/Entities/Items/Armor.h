#ifndef ARMOR_H_
#define ARMOR_H_

#include "EquippableItem.h"
class Armor : public EquippableItem{
public:
    BODY_LOCATION location; // armor location
    double stab_protection;
    double slash_protection;
    double burn_protection;
    double acid_projection;
    double radiation_projection; // not usually used in fantasy
    
    
    // inherited from DurableItem
    // double quantity, quality, weight, durability;
    // double rarity; // EquippableItem
    //  LinkedList<Enchantment> enchantments;
};

#endif
