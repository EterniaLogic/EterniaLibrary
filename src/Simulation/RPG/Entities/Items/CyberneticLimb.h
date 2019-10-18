#ifndef CYBERLIMB_H_
#define CYBERLIMB_H_

#include "EquippableItem.h"


// Prosthetic robotic limb. Can technically be any part of the body, but head would be a bad idea for a dumb limb.
//  --Can be enchanted, assuming that the world contains mana.



class CyberLimb : public EquippableItem{
public:
    BODY_LOCATION limbloc;
    
    double wattage; // battery usage based on active usage.
    
    
    // inherited from DurableItem
    // double quantity, quality, weight, durability;
    // double rarity; // EquippableItem
    
    //  LinkedList<Enchantment> enchantments;
};

#endif
