#ifndef ITEM_H_
#define ITEM_H_

#include "ItemBase.h"

// Very basic item, usually noted as loot or non-specific items.
// Basic items are also the base level for craftables.
class Item : public ItemBase {
    
public:
    Item();
};

#endif