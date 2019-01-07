#ifndef LOCATION_H_
#define LOCATION_H_

#include "../Data/includes.h"
#include "../Math/Math.h"

class Location : public SpecificSerializer {
    public:
        Location(double x, double y, double z, double dimension);
        Location(double x, double y, double z);
        Location();
        void setupSerialization();
        
        CharString name; // for locations such as addresses or a hazy definition of a world
        
        // xyz are standard location identifiers, dimension used for phasing in-between. (wxyz for short)
        double x,y,z,dim;
};

#endif
