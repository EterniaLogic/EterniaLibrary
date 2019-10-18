#ifndef HQUEEN_H_
#define HQUEEN_H_

#include "../Creature.h"

// Hive Queens are typically larger than workers/soldiers and sometimes even Majors.

class Human : public Creature{
public:
    Human(){
        classname="HiveQueen";
        _type = CT_Hive;
        stats.str = stats.vit = stats.spi = stats.will = stats.luck = stats.charisma = 20; // Level 0 stats
        stats.agi = 6; // super slow
        
        weight_kg = 3*40; // 3x human weight
        
        energy.calories = energy.calories_max = 20000; // Carbo=2000, fat > 2000
        energy.calories_fat = 6000*(weight_kg*0.11); // healthy human body fat (~11% body fat)
        energy.water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
        health.blood = health.bloodmax = 20; // 
    }
    
    
    void think(double seconds); // think?
    void tick(double seconds);
};

#endif
