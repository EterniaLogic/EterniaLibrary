#ifndef SOLAROBJECT_H
#define SOLAROBJECT_H

#include "../../Entity.h"
#include "../../../Math/Math.h"

class SolarObject : public Entity{
public:
    const double G = 6.67407e-11;
    
    double soi; // orbital parameters
	double radius, daylen, mass, volume, density, magnetosphere; // body parameters
	long long seed, seed2; // two seeds used for more specific objects
	
	
	double getCircumference() {
		return 2.*Math::PI*radius;
	}
	
	double getSurfaceGravity() {
		return (G*mass)/Math::pow(radius,2.);
	}
};

#endif
