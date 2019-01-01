#include "Planet.h"

Atmosphere::Atmosphere(long long seed, long long seed2){
    // determine the atmophere density
    // Atmospheres follow a ln curve.
}

Atmosphere::Atmosphere(){}

Atmosphere::~Atmosphere(){
    
}

// usesa sine wave to determine the density of the air according to the location.
double Atmosphere::getDensity(double relativeHeight) {
    // Earth standard values
    // t0 = 288.15 Kelvin (average sea temperature)
    // L = 0.0065 K/m (temperature lapse rate)
    // p0 = 101.325 kPa (density of earth at sea level)
    // H = height meters
    
    // Pressure of air at height
    // P = p0(1-[LH/t0])
}
