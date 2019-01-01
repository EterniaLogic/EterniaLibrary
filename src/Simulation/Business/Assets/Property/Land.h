#ifndef LAND_H_
#define LAND_H_

#include "../../ALocation.h"
#include "../../../Math/Math.h"
#include "../Asset.h"

// 
class Land : public Asset{
public:
    ALocation location;
    vertex dimensions;
    
    // use asset->value for valuation
};

#endif
