#ifndef LICH_H_
#define LICH_H_

#include "../RaceChanged.h"

// limbs and looks for a vampire are based off of their original race.

// Normally Liches are surrounded by armies of undead to protect their fragile body.
// Liches live in undead realms

class Lich : public RaceChanged{
public:
    Lich(){
        classname="Lich";
        _type = CT_Lich;
        
        // Level 0 stats
        stats.str = 2; // Literally a skeleton, since flesh is gone by the point people see the lich
        stats.agi = 5;
        stats.vit = 0; // undead
        stats.spi = 20; // Spirit is a lich's main point, The better the spirit the better to keep memories and arrange new spells.
        stats.will = 30; // Willpower affects undead army sizes, prevents necromancers from enslaving this lich.
        stats.luck = 20; // kind of have to have luck for the Lich conversion ritual to work.
        stats.charisma = 1; // not really that smooth in front of other races...
        
        health.regrowlimbs = true;
        health.uselimbs = true;
        health.useblood = false;
        health.immortal = true; // one cannot kill an elemental unless you destroy their soul (They respawn in the elemental planes)
        energy.usefood = false;
        energy.usewater = false;
        energy.createswaste = false;
        
        // HP/Food is souls. (Does not actually destroy souls, only skims off the energy of a mortal's birth before they are sent to the netherworld/reincarnation)
        health.hptype = HP_SOUL;
        
        energy.foodtype = FOODT_SOUL;
    }
};

#endif
