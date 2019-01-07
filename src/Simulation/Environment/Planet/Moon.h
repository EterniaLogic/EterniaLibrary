#ifndef MOON_H
#define MOON_H

#include "../Space/SolarObject.h"

class Moon : public SolarObject{
public:
    Moon(long _seed){this->seed = _seed;}
};


#endif
