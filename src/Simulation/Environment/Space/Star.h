#ifndef Star_H_
#define Star_H_

#include "../../../Data/includes.h"

// A star has a large mix of atoms. The sun is 70% Hydrogen, which is the active
//  fusion element. 26% of it has become Helium and denser elements.

// Helium will slowly turn into carbon over time, The process is exponentially
//  longer for fusion to happen to get denser elements.

enum STARTYPE {ST_RedDwarf, ST_BrownGiant, ST_BlackDwarf, ST_WhiteDwarf, ST_Neutron,
               ST_RedGiant, ST_BlueGiant, ST_BlueSuperGiant, ST_RedSuperGiant, ST_Sun
              };

class Star {
    public:
        Star();

        STARTYPE type;
        double radius, weight;
};

#endif
