#ifndef CREATUREPOOLS_H_
#define CREATUREPOOLS_H_

#include "../../../../Serialization/SpecificSerializer.h"

class CreaturePools : public SpecificSerializer{
public:
    
    double mp, MPMax; // Mana
    double sp, SPMax; // Stamina Pool (not used when 'usefood' is on)
    
    double MPRegen, SPRegen; // regen per minute
    
    CreaturePools();
    
    void tick(double seconds); // regeneration
};

#endif
