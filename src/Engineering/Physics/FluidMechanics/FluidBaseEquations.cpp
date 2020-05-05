#include "FluidBaseEquations.h"

using namespace Math;

// from basic physics equations
float _getGravity(float mass, float bigMass, float distance){
    // g = G(m*M)/r^2
    return (physical::constant::G * (bigMass * mass) / (distance*distance));
}

// note that p is pressure at xyz and g is the gravity in m/s^2 at that point xyz.
float pressureGradientPoint(float pressure, float gravity){
    return pressure*gravity;
}



// ideal gas law solved for pressure in Pascals, Temperature is in kelvin, Mole is a count of atoms (i.e.: 6*10^23 atoms)
float idealGasLaw_Pressure(float moles, float temperature, float volume){
    return (physical::constant::K_B * moles * temperature)/volume;
}

// ideal gas law solved for temperature in Kelvin T=PV/(nR)
float idealGasLaw_Temperature(float pressure, float volume, float moles){ 
    return ((pressure * volume)/(moles * physical::constant::K_B));
}

float idealGasLaw_Volume(float pressure, float temperature, float moles){ // ideal gas law solved for volume in liters V=nRT/P
    return (physical::constant::K_B*moles*temperature)/pressure;
}




// force upwards if any for a given object of massdensity
float buoyantForce(float massdensity, float displacedvolume, float gravity){
    return (-massdensity * displacedvolume * gravity);
}

// apparent weight given a weight outside fluid and buoyant force
float apparentWeight(float weight, float buoyantforce){ 
    return weight-buoyantforce;
}

float totalVolumeEnergy(float pressure, float internalenergy, vertex flowvelocity){
    // E=p(U+ (1/2 u^2))
}


vertex convectiveAcceleration(vertex flowvelocity, vertex gradient){
    return flowvelocity*flowvelocity.dot(gradient);
}
