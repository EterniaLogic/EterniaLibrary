#ifndef DISTILLERY_H_
#define DISTILLERY_H_


#include "Workshop.h"
class Distillery : public Workshop{
public:
    Distillery(){
        classname="Distillery";
        recipes.add(WorkshopRecipe("4L Grain Mash","1.2L Ethanol, 2ml Methanol, 10kg Biomass", 2400)); // create alcohol
        
        recipes.add(WorkshopRecipe("500ml impure mercury","490ml mercury, 10ml slag", 2400)); // purifying mercury
    }
};

#endif
