#ifndef INV_H_
#define INV_H_

#include "../../Object.h"
#include "../../../Data/includes.h"

class Inventory : public Object {
public:
    double usedspace; // precalculated space used by current items
    
    double space; // m3 of space, common is 25 liters of space or 25mm3  for a backpack.
    double maxweight; // max weight in kg, weight limited due to straps breaking. (Chests can carry like a ton)
    
    LinkedList<Item> items;
    
    Inventory(){
        classname = "Inventory";
    }
};

#endif
