#ifndef BACKPACK_H_
#define BACKPACK_H_

#include "EquippableItem.h"
#include "../Inventory.h"

// A Pack is equippable, (Backpack) or also can be used as a chest on the floor.
// Packs can also be waist pouches

class Pack : public EquippableItem{
public:
    Inventory inventory;
    
    Pack(){
        inventory.space = 0.025;
        inventory.usedspace = 0;
        inventory.maxweight = 25; // kg
    }
    
    // Enchant [space+pocket] for larger space
    
    
    // inherited from DurableItem
    // double quantity, quality, weight, durability;
    // double rarity; // EquippableItem
    //  LinkedList<Enchantment> enchantments;
};

#endif
