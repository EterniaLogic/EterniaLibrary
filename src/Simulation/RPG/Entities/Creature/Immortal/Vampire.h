#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "../RaceChanged.h"

// limbs and looks for a vampire are based off of their original race.

class Vampire : public RaceChanged{
public:
    Vampire(){
        classname="Vampire";
        _type = CT_Vampire;
        
        // Stats derived from original race
        // Str += 1 level
        // Agi += 1 level
        // Vit += 1 level
        
        // A vampire's age is the only way to level.
        
        
        health.regrowlimbs = true;
        health.uselimbs = true;
        health.useblood = true;
        health.immortal = true; // one cannot kill an elemental unless you destroy their soul (They respawn in the elemental planes)
        energy.usefood = false;
        energy.usewater = false;
        energy.createswaste = false;
        
        // HP/Food is their Blood.
        health.hptype = HP_HP;
        
        energy.foodtype = FOODT_BLOOD;
    }
};

#endif
