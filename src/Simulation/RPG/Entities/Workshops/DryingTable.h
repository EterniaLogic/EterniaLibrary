#ifndef DRYINGTABLE_H_
#ifndef DRYINGTABLE_H_

#include "Workshop.h"

class DryingTable : public Workshop{
public:
    DryingTable(){
        classname="DryingTable";
        // dry stuff out
        
        recipes.add(WorkshopRecipe("98ml lye water","soap bar")); // used ash can be used as a fertilizer
        recipes.add(WorkshopRecipe("5g wood pulp, 10ml water","1 paper sheet"));
    }
};

#endif
