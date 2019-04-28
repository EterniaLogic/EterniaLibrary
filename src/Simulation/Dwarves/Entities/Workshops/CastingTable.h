#ifndef ROLLER_H_
#define ROLLER_H_

#include "Workshop.h"

class CastingTable : public Workshop{
public:

    CastingTable(){
        classname="CastingTable";
        recipes.add(new Recipe("Liquid Metal, NOCONSUME Metal Shape Cast", "Casted Item", 200));
        recipes.add(new Recipe("Resin, NOCONSUME Any Shape Cast", "Resin Cast", 200));
    }
};

#endif
