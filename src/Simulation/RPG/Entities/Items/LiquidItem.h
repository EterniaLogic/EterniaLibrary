#ifndef LIQUIDITEM_H_
#define LIQUIDITEM_H_

#include "Item.h"
#include "../../../../Data/includes.h"



class LiquidItem : public Item{
public:
    double liters;
    // inherits name, volume, etc.
};

#endif
