#ifndef DWARF_H_
#define DWARF_H_

#include "Humanoid.h"

class Dwarf : public Humanoid{
public:
    Dwarf(){
        _type = CT_Dwarf;
        
        // limbs already inherited from Humanoid.
        
        weight_kg = 40; // average dwarf weight
        calories_use_rest = 0.42 *weight_kg;
        calories_use_excercise = 2*calories_use_rest;
        calories_use_vigorous = 4*calories_use_rest;
        
        calories = calories_max = 2000; // Carbo=2000, fat > 2000
        calories_fat = 4100*(weight_kg*0.11); // healthy human body fat (~11% body fat)
        water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
        blood = bloodmax = 4; // 4 liters on dwarven average
    }
    
    
    void think(double seconds); // think?
    void tick(double seconds);
};

#endif
