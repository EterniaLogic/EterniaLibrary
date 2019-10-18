#ifndef CREATURERESISTANCES_H_
#define CREATURERESISTANCES_H_

#include "../../../../Serialization/SpecificSerializer.h"

// Resistances are changeable and improvable.
//  Creatures, like elementals have nearly maximum resistance. (or 100%, 1.0f resistance)

class CreatureResistances : public SpecificSerializer{
public:
    // Physical, usually dealing with skin/scale resistances
    double Slashing;
    double Hacking;
    double Piercing; // Human skin cannot really handle piercing damage as compared to Dragon Scales.
    double Blunt;

    // Elemental
    double Fire; // does skin burn? 
    double Explosion; // has scales to protect from explosions? (Humans are pretty squishy, debris can easily pierce)
    double Water; // water damage is not to be confused with piercing damage.
    double Earth; 
    double Air; // can a very strong wind actually destroy the creature?
    
    double Light; // humans, dwarves, etc. have a fairly high resistance, while vampires and other dark creatures do not. (humans are not fully resistant due to UV rays)
    double Dark; // 
    double Void; // void damage is damage from the reality being torn apart. True 100% void damage would literally 'dissapear' a part of a being.
    
    double Mind; // Mental Magics affect the soul-mind.
    
    CreatureResistances(){
        // Defaults here are for common Material Plane beings
        Slashing = 0.2;
        Hacking = 0.2;
        Piercing = 0.2;
        Blunt = 0.2;
        
        Fire = 0.2;        
        Explosion = 0.2;
        Water = 0.7;
        Earth = 0.7;
        Air = 0.7;
        
        Light = 0.8;
        Dark = 0.2; // Most surface mortals fear the darkness. (Having 0% darkness resistance would actually damage a mortal if they were to be in it)
        Void = 0.1; // However, they fear the possbility of never existing at all.
        
        Mind = 0.1; // Most mortals are not immune to mental magic / Psionics.
    }
};


#endif
