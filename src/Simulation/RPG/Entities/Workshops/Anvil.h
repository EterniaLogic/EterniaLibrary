#ifndef ANVIL_H_
#define ANVIL_H_

#include "Workshop.h"

class Anvil : public Workshop{
public:
    
    Anvil(){
        classname="Anvil";
        recipes.add(WorkshopRecipe("NOCONSUME Metal Hammer, 1 Hot Metal Item","1 Semi-Hot Metal Item", 300));
        
        recipes.add(WorkshopRecipe("NOCONSUME Metal Hammer, 1 Hot Metal Item","1 Shaped Metal Item", 300)); // assuming that item has been fully shaped (Takes like 6-50 cycles)
    }
};

#endif
