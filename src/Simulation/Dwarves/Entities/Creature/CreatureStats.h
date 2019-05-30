#ifndef CREATURESTATS_H_
#define CREATURESTATS_H_

#include "../../../../Serialization/SpecificSerializer.h"

class CreatureStats : public SpecificSerializer{
public:
    int level; // level
    
    bool canlevel;
    
    //double FP, FPMax; // Calories/max
    double str,agi,vit,spi,will,luck,charisma; // 10 = human
    double attributepoints; // spare attribute points
    
    CreatureStats();
};


#endif
