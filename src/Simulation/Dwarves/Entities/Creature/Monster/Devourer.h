#ifndef DEVOUR_H_
#define DEVOUR_H_


// Dopelganger+, no forceful shapes/rules that dopelgangers have.

// A devourer has an internal spatial pouch for biomass.
// Biomass can be used by the devourer as both health and structure.

// The food/hunger pool and health pools are nearly the same, except that food has a percentage wasted based on the Devouring skill.

#include "IntelligentCreature.h"
#include "Skill/Skill.h"

class Devourer : public IntelligentCreature{
public:

    RaceCaste* disguiserace; // race being disguised as
    

    Devourer(){
        classname = "Devourer";
        _type = CT_Devourer;
        skills.add(new Skill("Devouring", 1, 100, 0));
        limbs.add(new Limb(BL_UNKNOWN, 100, 100, 0)); // devourer biomass sludge (1 for every kg?)
        
        energy.usefood = true;
        energy.foodtype = FOODT_OMNIVORE;
        health.uselimbs = false;
        health.useblood = false;
        health.immortal = true;
        
        health.regrowlimbs = true;
        
        health.hptype = HP_FOOD; // HP pool is the food pool
        
        
        weight_kg = 10; // blob?
        
        energy.calories_use_rest = 0.05;
        energy.calories_use_excercise = 0.3;
        energy.calories_use_vigorous = 0.5;
        
    }
};

#endif
