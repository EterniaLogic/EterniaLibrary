#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "../Asset.h"

class Material : public Asset{
public:
    double volume; // liters
    double weight; // kg
    
    Material(){
        type = AT_MATERIAL;
        volume = weight = 0;
    }
};

#endif
