#include "CreaturePools.h"

CreaturePools::CreaturePools(){
    mp=MPMax=100;
    sp=SPMax=2000;
    
    MPRegen = 1;
    SPRegen = 1;
    
    addSerial_N(mp, SSE_double);
    addSerial_N(MPMax, SSE_double);
    addSerial_N(MPRegen, SSE_double);
    addSerial_N(sp, SSE_double);
    addSerial_N(SPMax, SSE_double);
    addSerial_N(SPRegen, SSE_double);
}

// regeneration
void CreaturePools::tick(double seconds){
    mp = mp*MPRegen*(seconds/60);
    sp = sp*SPRegen*(seconds/60);
}
