#ifndef TREEC_H_
#define TREEC_H_

// A devourer has an internal spatial pouch for biomass.
// Biomass can be used by the devourer as both health and structure.

// The food/hunger pool and health pools are nearly the same, except that food has a percentage wasted based on the Devouring skill.

#include "../IntelligentCreature.h"
#include "../../Skill/Skill.h"

class Tree : public IntelligentCreature{
public:
    Tree(){
        classname="Tree";
        _type = CT_Tree;
        skills.add(new Skill("Hibernate", 1, 100, 0)); // tree-souls can fall asleep
        limbs.add(new Limb(BL_UNKNOWN, 100, 100, 0)); // tree limb base
        
        energy.usefood = true; // food derived from sun
        health.uselimbs = true;
        health.useblood = true; // treesap
        
        
        health.hptype = HP_FOOD; // HP pool is the food pool
        energy.calories_conversion_sun = 100; // 100 calories per hour in sun
        
        blood = bloodmax = 20; // trees can lose a lot of sap and still survive
        
        
        soul.age = 0; // most trees have baby souls
    }
};

#endif
