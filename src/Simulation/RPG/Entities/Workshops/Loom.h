#ifndef LOOM_H_
#define LOOM_H_

#include "Workshop.h"
class Loom : public Workshop{
public:
    Loom(){
        classname="Loom";
        // Fabrics can be made out of cotton, hemp, wool, steel wool
    
        recipes.add(new Recipe("1kg Cotton","2000cm2 Cotton Fabric", 3600));
        recipes.add(new Recipe("1kg Polyester","2000cm2 Polyester Fabric", 3600));
        recipes.add(new Recipe("1kg Hemp","2000cm2 Hemp Fabric", 3600));
        recipes.add(new Recipe("1kg Wool","2000cm2 Wool Fabric", 3600)); // yarn
    }
};

#endif
