#ifndef EQITEM_H_
#define EQITEM_H_


#include "DurableItem.h"
#include "Enchantment.h"

class EquippableItem : public DurableItem {
public:
    double rarity; // rarity effects the overall quality of the item due to items used
    
    LinkedList<Enchantment> enchantments;
};

#endif
