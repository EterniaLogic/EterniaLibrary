#ifndef DEVIL_H_
#define DEVIL_H_

#include "../IntelligentCreature.h"

// Devils are the antithesis to Gods.
// The standard Devil's perogative is to grow by eating the excess energy of souls. (Souls cannot actually be destroyed, they just eat the excess MP and memories)

// Devils start out as an Imp when they are incarnated, or when they are 'reset'. (devil dimensions version of death)
// Imps are dumb, but can evolve to become a 7-sins demon.


enum DEVILSEVENSIN {DSS_NONE, DSS_PRIDE, DSS_GREED, DSS_GLUTTONY, DSS_LUST, DSS_SLOTH, DSS_WRATH, DSS_ENVY};

class Devil : public IntelligentCreature{
public:
    DEVILSEVENSIN sin;
    CharString subtype; // sub-type of demon: Imp, Fiend, Succubus, Fallen Angel, Banshee, Behemoth, etc.

    Devil(){
        classname="Devil";
        _type = CT_Devil;
        health.regrowlimbs = true;
        health.uselimbs = false;
        health.useblood = false;
        health.immortal = true; // one cannot kill an elemental unless you destroy their soul (They respawn in the elemental planes)
        energy.usefood = false;
        energy.foodtype = FOODT_SOUL;
        energy.usewater = false;
        energy.createswaste = false;
        
        // HP is their soul-hp, but they cannot easily die. (AKA: death will send them back to the Devil domain, full-death in the devil domain will 'Resart' their life and memories in the devil domain)
        //  Soul HP only goes to a certain point, they will be ejected from the dimension if they are hurt too much at once.
        hptype = HP_SOUL; 
        
        // one of the few creatures that can eat souls. Their souls will grow in health and MP.
        soul.eatsouls = true;
        
        sin = DSS_NONE; // sin type assigned later on after imp-stage of growth.
        subtype = "Imp"; // Standard low-level grunt, no seven-sin designation.
    }
};

#endif
