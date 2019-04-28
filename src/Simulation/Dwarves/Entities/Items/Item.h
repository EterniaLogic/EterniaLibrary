#ifndef ITEM_H_
#define ITEM_H_

#include "../../../Object.h"
#include "../../../../Data/includes.h"

class Item : public Object{
public:
    double quantity; // number for countable items
    double volume; // liters for liquid, m3 for gas/earth
    double weight; // per item kg (or per liter weight, per m3 weight)
    CharString name, description;
    CharString category; // string category allows for multiple items to have the same category, like ore dusts, seeds or wood types, Metal Ingot
    
    Item fromQtyName(CharString name); // "1kg Coal"   => Coal (1kg, 740 um3)
    CharString toQtyName(); // "1kg coal", "500mm3 water"
};

#endif
