#ifndef LWEAPON_H_
#define LWEAPON_H_

#include "Weapon.h"
class LevelWeapon : public Weapon{
public:
    int level;
    double exp;
    
    
    // inherited from DurableItem
    // double quantity, quality, weight, durability;
    // double rarity;
    //  LinkedList<Enchantment> enchantments;
    
    // bool doublehanded;
    // double stab, slash, burn, acid, radiation;
};

#endif
