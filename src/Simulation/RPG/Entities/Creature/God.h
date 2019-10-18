#ifndef GOD_H_
#define GOD_H_

#include "IntelligentCreature.h"

// Gods are semi-present, only there when their believers are there.

class God : public IntelligentCreature{
public:

    // belief is a quantifiable value, 1 unit is 1 believer devoutly praying for a year.
    //  Gods can be killed if their belief reaches zero or their dominion is stolen/corrupted.
    double belief;
    CharString domain; // concept or element which this God is reponsible for governing.

    God(){
        _type = CT_God;
        health.uselimbs = false;
        health.regrowlimbs = true; // can regrow limbs?
        health.useblood = false;
        health.immortal = true; // one cannot kill a god unless you destroy their soul (Belief resurrects them)
        energy.usefood = false;
        energy.usewater = false;
        stats.canlevel = false; // Gods cannot gain material power
        
        hptype = HP_BELIEF;
        
        
        // soul must be the same attunement as the god's domain type if an elemental type.
        // soul.attunement = SA_LIGHT;
        // God of War might be fighting for the LIGHT for example depending on the God's disposition.
    }
};

#endif
