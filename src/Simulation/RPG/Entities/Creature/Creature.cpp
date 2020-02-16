#include "Creature.h"


// Default values provided here are based on an average human male
Creature::Creature(){
    classname="[Creature]";
    alive=true; // would be nice to have
    energy.health = &health;
    health.energy = &energy;
    
    _type=CT_Unknown;
    _class=CCL_NONE;
    
    weight_kg = 81; // average human male
    
    
    health.uselimbs = true;
    health.regrowlimbs = false; // most creatures cannot regrow limbs
    health.useblood = false;
    health.immortal = false; // most creatures can be disconnected from their souls.
    energy.usefood=true; // use calories
    energy.usewater=true; // use calories
    energy.canstarvetodeath = true;
    energy.createswaste = true;
    stats.canlevel = false; // Gods cannot gain material power
    stats.canlevel = true;
    pools.mp = pools.MPMax = 100; // soul also has MP alongside Psi.
    pools.sp = pools.SPMax = 100;
    
    mother = father = 0x0;
    
    _initSerializers(); // only for Creature, make other names for function?
    
    
}

void Creature::_initSerializers(){
    
    addSerial(&alive, "alive", SSE_bool);
    addSerial(&weight_kg, "weight_kg", SSE_double);
    addSerial(&age, "age", SSE_double);
    addSerial(&_type, "type", SSE_Int);
    addSerial(&_class, "class", SSE_Int);
    
    
    addSerial(&spells, "spells", SSE_LinkedList);
    addSerial(&skills, "skills", SSE_LinkedList);
    addSerial(&actionqueue, "actionqueue", SSE_LinkedList);
    
    addSerial(&mother->name, "mother_name", SSE_CharString);
    addSerial(&father->name, "mother_name", SSE_CharString);
    //addSerial(&children, "children", SSE_LinkedList);
    
    
    addSerial(&soul, "soul", SSE_SSerializer);
    addSerial(&health, "health", SSE_SSerializer);
    addSerial(&energy, "energy", SSE_SSerializer);
    addSerial(&stats, "stats", SSE_SSerializer);
    addSerial(&pools, "pools", SSE_SSerializer);
}

void Creature::_tick(double seconds){
    if(!alive) return;
    
    // humans do selfheal, but REALLY slowly
    
    
    if(energy.usefood)      energy.starve(seconds); // use food! if possible, starve to death!
    if(energy.usewater)     energy.thirst(seconds);
    
    
    health.selfheal(energy, seconds);
    
    
    if(!health.isAlive()){
        alive=false;
    }
    
    
    age = age*(seconds/(60*60*24*365)); // add to age
    soul._tick(seconds);
    pools.tick(seconds);
    health.tick(seconds);
    tick(seconds);
}

void Creature::_movetick(double seconds){
    // move creature
    
    // ?
    movetick(seconds);
}

void Creature::tick(double seconds){
    // provided by subclass
}

void Creature::movetick(double seconds){
    // provided by subclass
}


