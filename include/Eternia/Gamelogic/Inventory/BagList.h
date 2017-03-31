#ifndef BAGLIST_H_
#define BAGLIST_H_

#include "../../Data/LinkedList.hpp"
#include "BaseInventory.h"

// Some specific RPGs have multiple inventory bags.
class BagList{
private:
    LinkedList<BaseInventory> bags;
public:
    BagList();
};

#endif