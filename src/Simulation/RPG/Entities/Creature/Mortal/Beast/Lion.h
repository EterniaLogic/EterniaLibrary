#ifndef LION_BEAST_H_
#define LION_BEAST_H_

#include "../../Quadrupedal.h"

class Lion : public Quadrupedal{
public:
    Lion(){
        classname="Lion";
        _type = CT_Beast_Lion;
        
        // limbs already inherited from Quadrupedal.
        
        weight_kg = 260; // average weight
        
        energy.calories = energy.calories_max = 2000; // Carbo=2000, fat > 2000
        energy.calories_fat = 4100*(weight_kg*0.11); // healthy dwarven body fat (~11% body fat)
        energy.water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
        
        health.blood = health.bloodmax = 10; // 10 liters
    }
};

#endif
