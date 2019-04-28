#include "CreatureEnergy.h"

CreatureEnergy::CreatureEnergy(){
    calories = calories_max = 2000; // Carbo=2000, fat > 2000
    calories_fat = 4100*(81*0.11); // healthy human body fat (~11% body fat)
    water_per = 100; // percentage of water of min/max diet, 3 days = 0% = death
    calories_use_rest = 0.42; // *weight_kg per
    calories_use_excercise = 2*calories_use_rest;
    calories_use_vigorous = 4*calories_use_rest;
    calories_conversion_gain = 0.4; // humans only convert 25-50% of food energy
    
    water_use = 100/(3*24*60*60); // 3 days worth of water
    calories_use = calories_use_rest; // currently sitting down
    
    // Food type that can digest
    foodtype = FOODT_OMNIVORE;
}

void CreatureEnergy::starve(double seconds){
    // use caloric energy per second
    
    double hour = 60*60; // seconds
    double hours = seconds/hour;
    
    calories -= (calories_use/(hour))*seconds;

    // convert food in stomach into calories (6 hours)
    double stom_rate = calories_stomach * (hours/6);
    calories += stom_rate * calories_conversion_gain;
    calories_stomach -= stom_rate;
    
    
    // Ketosis, start using body fat via Lipolysis
    if(calories < calories_max*0.8){
        if(calories_fat > 100){ // Ketosis can occur
            double calc = calories_fat * (seconds/60);
            calories += calc * 0.8; // some lost when converting to glucose
            calories_fat -= calc;
        }else{
            // some fat cannot be converted easily now. Damage organs/health.
        }
    }
}

void CreatureEnergy::thirst(double seconds){
    // perspire, "..." or convert water into vapor
    
    water_per = water_per * (seconds * water_use);
    
    // start to damage the organs
    if(water_per < 0.2){
        
    }else if(water_per <= 0.05){ // die!
        health->stopHeart(); // stop the heart, 4 minutes until true death
    }
}
