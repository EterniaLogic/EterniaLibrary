#ifndef ELEMENTAL_H_
#define ELEMENTAL_H_

#include "IntelligentCreature.h"

// Elementals are unique in that their health pool is based off of their mana pool.

class Elemental : public IntelligentCreature{
public:
    Elemental(){
        _type = CT_Elemental;
        health.regrowlimbs = true;
        health.uselimbs = false;
        health.useblood = false;
        health.immortal = true; // one cannot kill an elemental unless you destroy their soul (They respawn in the elemental planes)
        energy.usefood = false;
        energy.usewater = false;
        
        hptype = HP_MANA; // HP is mana, but cannot die
    }
};

#endif
