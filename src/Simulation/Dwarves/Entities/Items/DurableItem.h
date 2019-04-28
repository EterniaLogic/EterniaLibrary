#ifndef DITEM_H_
#define DITEM_H_

#include "Item.h"
class DurableItem : public Item{
public:
    double quality; // Quality effects durability and protection
    double durability;
    
    
    // inherited from Item
    // double quantity, weight;
};

#endif
