#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "../IntelligentCreature.h"

// outward appearance might be difficult to determine.
// if a quadrupedal race is stronger than the other races, going to be quadrupedal

class Halfling : public IntelligentCreature{
public:
    Caste *a, *b, *c, *d; // dependent on ancestry
    
    double ratioa, ratiob, ratioc, ratiod;
    
    Halfling(){
        classname="[Halfling]";
        
    }
};

#endif
