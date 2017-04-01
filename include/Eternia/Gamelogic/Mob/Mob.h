#ifndef Mob_h_
#define Mob_h_

#include "../Avatar/Avatar.h"

// A mob is a "monster", or an enemy of some kind.
// AI is based on the game being made.

class Mob : public Avatar {
    public:
        Mob(); // default attributes


    private:
        // Static attributes
        double hear_range; // Aggro algorithm requires direct sight or sound.
        double vision_range;
};

#endif
