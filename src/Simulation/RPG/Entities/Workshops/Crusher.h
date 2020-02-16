#ifndef CRUSHER_H_
#define CRUSHER_H_

#include "Workshop.h"
class Crusher : public Workshop{
public:
    Crusher(){
        classname="Crusher";
        recipes.add(WorkshopRecipe("Raw Ore","Raw Ore Dust")); // Percentage outputs based on ore yield
        recipes.add(WorkshopRecipe("Rock","Silica Dust"));
    }
};

#endif
