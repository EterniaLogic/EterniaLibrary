#ifndef HUMAN_H_
#define HUMAN_H_

#include "../Humanoid.h"

class Human : public Humanoid{
public:
    Human(){
        classname="Human";
        _type = CT_Human;
        
        // limbs already inherited from Humanoid.
        
        weight_kg = 81; // average human weight
        
        energy.calories = energy.calories_max = 2000; // Carbo=2000, fat > 2000
        energy.calories_fat = 4100*(weight_kg*0.11); // healthy human body fat (~11% body fat)
        energy.water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
        health.blood = health.bloodmax = 5; // 4 liters on dwarven average
    }
    
    
    void think(double seconds); // think?
    void tick(double seconds);
};

#endif
