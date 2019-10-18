#ifndef WEAVER_H_
#define WEAVER_H_

#include "Workshop.h"
class Weaver : public Workshop{
public:
    Weaver(){
        classname = "weaver";
        // Fabrics can be made out of cotton, hemp, wool, steel wool
    
        recipes.add(new Recipe("1 Fabric","Shirt"));
        recipes.add(new Recipe("1 Fabric","Pants"));
        recipes.add(new Recipe("1 Fabric","Hat"));
        recipes.add(new Recipe("1 Fabric","Socks"));
    }
};

#endif
