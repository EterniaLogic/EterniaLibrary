#ifndef BaseInventory_h_
#define BaseInventory_h_

#include "../../Data/LinkedList.hpp"
#include "ItemBase.h"

class BaseInventory
{
public:
  BaseInventory();
  
private:
  LinkedList<ItemBase>* inventoryItems;
  int num_slots; // number of inventory slots
};

#endif