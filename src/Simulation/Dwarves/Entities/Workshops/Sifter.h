#ifndef SIFTER_H_
#define SIFTER_H_

#include "Workshop.h"
class Sifter : public Workshop{
public:
    Sifter(){
        classname="Sifter";
        recipes.add(new Recipe("Raw Ore Dust","Ore Dust, Silicon dust"));
        recipes.add(new Recipe("Dirt","organic matter, Silicon dust, aluminum dust, iron dust, magnesium dust, calcium dust, sodium dust, potassium dust"));
        //recipes.add(new Recipe("Sand","Silicon dust"));
    }
};

#endif
