#include "Work.h"

// Set all the values to zero.
Work::Work(float Mass){
    mass = Mass; 
    TEnergy=0;
    listOfTypes = new LinkedList<EnergyValue>();
}

// compute all of the energy values based on inputs
float Work::compute(){
    //Pg = mgh
    //GEnergy = mass*Gravity*height;
    //GSEnergy = 
    //KEnergy = 0.5f * mass * velocity * velocity;
    //KSEnergy = 0.5f * mass * RotVelo * RotVelo;
    
    //TEnergy = potentialGravity + kineticEnergy;
    return TEnergy;
}

// returns the total watts from the system
float Work::getTotalWatts(float time){
    // prevent divide-by-zero
    if(time == 0) time = 0.00000000000001;
    
    return TEnergy / time;
}
