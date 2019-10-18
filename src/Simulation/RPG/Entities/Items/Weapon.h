#ifndef WEAPON_H_
#define WEAPON_H_

#include "EquippableItem.h"
class Weapon : public EquippableItem{
public:
    bool doublehanded;
    double stab; // arrows count
    double slash;
    double burn;
    double acid;
    double radiation; // not usually used in fantasy
    
    
    // inherited from DurableItem
    // double quantity, quality, weight, durability;
    // double rarity; // EquippableItem
    
    //  LinkedList<Enchantment> enchantments;
};

#endif
