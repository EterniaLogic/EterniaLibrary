#ifndef BOILER_H_
#define BOILER_H_

#include "Workshop.h"

class Boiler : public Workshop{
public:
    double temperature; // temperature in celcius
    
    Boiler(){
        classname="Boiler";
        
        // 
        recipes.add(WorkshopRecipe("100ml Liquid","120ml Gas", 800));
    }
};

#endif
