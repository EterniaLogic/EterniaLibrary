#ifndef FLUIDBASEEQ_H_
#define FLUIDBASEEQ_H_

#include "../../../constants.h"
#include "../../../Math/Math.h"

// Base equations for fluids, from bernoulli, Euler and Navier-Stokes.
// Note that some equations become equations themselves or solve into vectors or 2D gradients.


float _getGravity(float mass, float distance); // from basic physics equations
float pressureGradientPoint(float pressure, float gravity); // note that p is pressure at xyz and g is the gravity in m/s^2 at that point xyz.


// Ideal Gas Law helps with the relationship between pressure and temperature (PV = nRT)
//  Temperature is in kelvin
//  Mole is a count of atoms (i.e.: 6.022*10^23 atoms, most molecules have a given gram/mol count as a constant)
//  Pressure is in pascals
//  Volume is in Liters
float idealGasLaw_Pressure(float moles, float temperature, float volume); // ideal gas law solved for pressure in kPa (P=nRT/V)
float idealGasLaw_Temperature(float pressure, float volume, float moles); // ideal gas law solved for temperature in Kelvin T=PV/(nR)
float idealGasLaw_Volume(float pressure, float temperature, float moles); // ideal gas law solved for volume in liters V=nRT/P


float buoyantForce(float massdensity, float volume, float gravity); // in Newtons
float apparentWeight(float weight, float buoyantforce); // apparent weight given a weight outside fluid and buoyant force

Math::vertex convectiveAcceleration(Math::vertex flowvelocity, Math::vertex gradient);


// Euler Equation results
float totalVolumeEnergy(); // in Joules

// solutions and outputs to Navier-Stokes equations

#endif
