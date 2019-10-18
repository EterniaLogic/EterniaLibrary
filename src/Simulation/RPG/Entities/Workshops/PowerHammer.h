#ifndef POWERHAMMER_H_
#define POWERHAMMER_H_

#include "Workshop.h"

class PowerHammer : public Workshop{
public:
    
    PowerHammer(){
        classname="PowerHammer";
        powertype = WSP_ELECTRICITY;
        wattage = 4800;
    
        recipes.add(new Recipe("1 Hot Metal Item","1 Semi-Hot Metal Item", 50));
        
        recipes.add(new Recipe("1 Hot Metal Item","1 Shaped Metal Item", 50)); // assuming that item has been fully shaped (Takes like 6-50 cycles)
    }
};

#endif
