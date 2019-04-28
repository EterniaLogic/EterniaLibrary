#ifndef WORKSHOP_H_
#define WORKSHOP_H_

#include "../../../Object.h"
#include "../../../../Data/includes.h"
#include "WorkshopRecipe.h"

enum WORKSHOPPOWER {WSP_NONE, WSP_ELECTRICITY, WSP_SOLIDFUEL, WSP_LIQUIDFUEL};

class Workshop : public Object{
public:
    LinkedList<WorkshopRecipe> recipes;
    Object addon; // Addons allow for extra capacity or w/e
    
    WORKSHOPPOWER powertype;
    double wattage;
    
    Workshop(){
        classname = "[Workshop]";
    }
};

#endif
