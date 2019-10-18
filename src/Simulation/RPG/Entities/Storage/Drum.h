#ifndef DRUM_H_
#define DRUM_H_

#include "../../../Data/includes.h"
#include "../Items/LiquidItem.h"

// Drums hold single liquids
class Drum{
public:
    LinkedList<Item> liquids;
    Drum();
};

#endif
