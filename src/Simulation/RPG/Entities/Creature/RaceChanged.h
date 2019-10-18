#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "../IntelligentCreature.h"

// limbs and looks for a vampire are based off of their original race.
// Undead, such as Liches, Skeletons, Zombies, etc.
// Werewolves, other werebeasts.

class RaceChanged : public IntelligentCreature{
public:
    Caste* previousCaste;
    
    RaceChanged(){
        classname="RaceChanged";
        
    }
};

#endif
