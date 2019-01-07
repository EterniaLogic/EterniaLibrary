#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "../../Data/includes.h"
#include "Universe/ULaw.h"

// A universe houses all galaxies and nebulae.
// The inner workings of the universe are derived via the LAWs of it.

class Universe {
    long seed;
    LinkedList<ULaw> laws;
public:
    Universe(long seedx){seed=seedx;}
    Universe(){seed=0;}
    
    // get a galaxy using a seed (seed also doubles as XYZ coordinates from the center of everything)
    Galaxy getGalaxy(long seed_xyz);
};

#endif
