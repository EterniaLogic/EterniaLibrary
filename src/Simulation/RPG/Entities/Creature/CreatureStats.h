#ifndef CREATURESTATS_H_
#define CREATURESTATS_H_

#include "../../../../Serialization/SpecificSerializer.h"

// Levels each give 1*level attribute points.

class CreatureStats : public SpecificSerializer{
public:
    int level; // level
    
    bool canlevel;
    
    //double FP, FPMax; // Calories/max
    double str,agi,vit,spi,will,luck,charisma; // 10 = human
    double attributepoints; // spare attribute points (Level 70 has sum(1,level) points)
    
    CreatureStats();
};


#endif
