#include "CreaturePools.h"

CreaturePools::CreaturePools(){
    MP=MPMax=100;
    SP=SPMax=2000;
    
    MPRegen = 1;
    SPRegen = 1;
    
    addSerial_N(MP, SSE_double);
    addSerial_N(MPMax, SSE_double);
    addSerial_N(MPRegen, SSE_double);
    addSerial_N(SP, SSE_double);
    addSerial_N(SPMax, SSE_double);
    addSerial_N(SPRegen, SSE_double);
}

// regeneration
void CreaturePools::tick(double seconds){
    MP = MP*MPRegen*(seconds/60);
    SP = SP*SPRegen*(seconds/60);
}
