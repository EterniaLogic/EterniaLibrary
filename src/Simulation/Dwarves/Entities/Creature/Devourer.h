#ifndef DEVOUR_H_
#define DEVOUR_H_

// A devourer has an internal spatial pouch for biomass.
// Biomass can be used by the devourer as both health and structure.

// The food/hunger pool and health pools are nearly the same, except that food has a percentage wasted based on the Devouring skill.

#include "IntelligentCreature.h"
#include "Skill/Skill.h"

class Devourer : public IntelligentCreature{
public:
    Devourer(){
        _type = CT_Devourer;
        skills.add(new Skill("Devouring", 1, 100, 0));
        limbs.add(new Limb(BL_UNKNOWN, 100, 100, 0)); // devourer biomass sludge
        
        energy.usefood = true;
        health.uselimbs = false;
        health.useblood = false;
        
        health.regrowlimbs = true;
        
        health.hptype = HP_FOOD; // HP pool is the food pool
    }
};

#endif
