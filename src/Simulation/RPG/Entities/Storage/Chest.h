#ifndef CHEST_H_
#define CHEST_H_

#include "../Inventory.h"
#include "../../../../Data/includes.h"

class Chest : public Inventory{
public:
    // double usedspace; // precalculated space used by current items
    // double space; // m3 of space, common is 25 liters of space or 1m3  for a chest.
    // double maxweight; // max weight in kg, weight limited due to straps breaking. (Chests can carry like a ton)
    // LinkedList<Item> items;
    
    Chest(){
        usedspace=0;
        space = 1; // 1 m3
        maxweight = 1000; // 1 metric ton
    }
};

#endif
