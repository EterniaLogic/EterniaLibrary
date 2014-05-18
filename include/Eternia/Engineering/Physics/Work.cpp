#include "Work.h"

// Set all the values to zero.
Work::Work(double Mass){
    mass = Mass; 
    TEnergy=0;
    listOfTypes = new LinkedList<EnergyValue>();
}

// compute all of the energy values based on inputs
double Work::compute(){
    //Pg = mgh
    //GEnergy = mass*Gravity*height;
    //GSEnergy = 
    //KEnergy = 0.5f * mass * velocity * velocity;
    //KSEnergy = 0.5f * mass * RotVelo * RotVelo;
    
    //TEnergy = potentialGravity + kineticEnergy;
    return TEnergy;
}

// returns the total watts from the system
double Work::getTotalWatts(double time){
    // prevent divide-by-zero
    if(time == 0) time = 0.00000000000001;
    
    return TEnergy / time;
}
