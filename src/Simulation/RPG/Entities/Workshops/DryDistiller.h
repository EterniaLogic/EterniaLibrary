#ifndef DRYDISTILLER_H_
#define DRYDISTILLER_H_

#include "Workshop.h"

// http://www.fao.org/3/x5555e/x5555e03.htm

class DryDistiller : public Workshop{
public:
    DryDistiller(){
        classname="DryDistiller";
        // Converts wood to multiple products
        
        // wood gas is only usable as fuel and consists typically of 17% methane; 2% hydrogen; 23% carbon monoxide; 38% carbon dioxide; 2% oxygen and 18% nitrogen.
        // liquid values here are incorrect
        recipes.add(WorkshopRecipe("1kg wood","200mg charcoal, 20ml ethyl, 10ml tar, 10ml wood vinegar, 1ml formaldehyde, 100ml water\
18ml nitrogen, 2ml oxygen, 38ml co2, 23ml carbon monoxide, 17ml methane, 2ml hydrogen", 1200)); // gasses

        // coal coke making
        recipes.add(WorkshopRecipe("1kg coal","700mg coal coke, 1l ammonia, 500ml coal tar, 0.4ml coal gas", 1500);
    }
};

#endif
