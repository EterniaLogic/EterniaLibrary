#ifndef GOD_H_
#define GOD_H_

#include "../IntelligentCreature.h"
#include "GodDomain.h"

class Religion;
#include "../../Religion.h"

// Gods are semi-present, only there when their believers are there.
// They can be any shape and their body is semi-material depending on their location.
// Attacking a god is a stupid idea unless the god is attacked

class God : public IntelligentCreature{
public:

    // belief is a quantifiable value, 1 unit is 1 believer devoutly praying for a year.
    //  Gods can be killed if their belief reaches zero or their dominion is stolen/corrupted.
    double belief;
    GodDomain* domain; // [Dimension] and concept or element which this God is reponsible for governing.
    Religion* religion; // Connected religion that provides belief over time.

    God(){
        classname="God";
        _type = CT_God;
        belief=1; // at least 1 believer to be a god.
        
        health.uselimbs = false; // Gods can be any shape they like.
        health.regrowlimbs = true; // can regrow limbs?
        health.useblood = false;
        health.immortal = true; // one cannot kill a god unless you destroy their soul (Belief resurrects them)
        energy.usefood = false;
        energy.usewater = false;
        energy.createswaste = false;
        stats.canlevel = false; // Gods cannot gain material power
        
        health.hptype = HP_BELIEF; // belief is the god's power/health structure (does not affect soul)
        
        
        // God souls are slightly more chunky due to being surrounded by faith all day long.
        soul.HP = soul.HPMax = 10000000;
        soul.HPRegen = 0.004; // fairly fast compared to mortals who are ~1000x slower.
        
        
        // soul must be the same attunement as the god's domain type if an elemental type.
        // soul.attunement = SA_LIGHT;
        // God of War might be fighting for the LIGHT for example depending on the God's disposition.
    }
};

#endif
