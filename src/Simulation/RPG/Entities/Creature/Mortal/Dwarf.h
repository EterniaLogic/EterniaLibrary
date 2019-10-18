#ifndef DWARF_H_
#define DWARF_H_

#include "../Humanoid.h"

class Dwarf : public Humanoid{
public:
    Dwarf(){
        classname="Dwarf";
        _type = CT_Dwarf;
        
        // limbs already inherited from Humanoid.
        
        
        stats.str = 9; // smaller?
        stats.agi = 11;
        stats.vit = 10;
        stats.spi = 10;
        stats.will = 11;
        stats.luck = 12; // higher luck for crafters
        stats.charisma = 10;
        
        weight_kg = 40; // average dwarf weight
        
        energy.calories = energy.calories_max = 2000; // Carbo=2000, fat > 2000
        energy.calories_fat = 4100*(weight_kg*0.11); // healthy dwarven body fat (~11% body fat)
        energy.water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
        
        health.blood = health.bloodmax = 4; // 4 liters on dwarven average
    }
    
    
    void think(double seconds); // think?
    void tick(double seconds);
};

#endif
