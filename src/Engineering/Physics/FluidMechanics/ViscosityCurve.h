#ifndef VISCOSITYCURVE_H_
#define VISCOSITYCURVE_H_

#include "../../../Data/includes.h"
#include "TempViscosityPoint.hpp"

// Viscosity changes based on temperature.
// This determines the Viscosity Curve based on given information.
// solves for Mu and stores it for usage, cPs units.
//  Mu solves for infinity if below 'lowest temperature', 0.01 at highest
// data pulled from Wikipedia

// Mu = (N_a*h/V)e^(3.8*T_b/T)   [Not used]
// Mu = Ae^(B/(T-C))             [Used]
// Unit Pa·s = Pascal second
// Unit mPa·s = milli-Pascal second   (liquids)
// Unit μPa·s = micro-Pascal second   (for gases)
// Unit cps  = mPa·s
// Unit Poiseuille = Pa·s


// Water = 1.8 mPas @ 272.6 Kelvin --- 0.01 mPas @ 623.15 Kelvin


// Water with 5-30% inaccuracy. (test data was inaccurate)
//      ViscosityCurve(1.0e-4, -92.210946, -140.0, 272.6)

// 25 Celcus = 277.6 Kelvin
/*  Water               0.89 mPa·s
    Mercury             1.526 mPa·s
    Ethanol             1.074 mPa·s
    Honey               100 Pa·s
*/


class ViscosityCurve {
private:
    double A, B, C, V;
    double lowesttemp; // starting temperature for a liquid/gas. (since assumed inifity if a solid)

public:
    ViscosityCurve(); // assumes data will be entered incrementally
    ViscosityCurve(double V); // not a curve, constant (Very inaccurate at any other temperature than assumed)
    ViscosityCurve(double A, double B, double C, double freezingtemp); // assumes data already solved for.
    ViscosityCurve(LinkedList<TempViscosityPoint*> points, double freezingtemp); // solve List of points in temperature and viscosity.
    
    void solveCurve(LinkedList<TempViscosityPoint*> points); // highest temp assumes 0.01 or less viscosity.
    
    float getViscosity(float temperature); // get viscosity from Kelvin temperature
    
    
    // internal constants
    double getA();
    double getB();
    double getC();
    double getLowestTemp();
    
    // uses known viscosities and scales them to fit a gas or liquid.
    // default: helium for gas, water for liquid
    static ViscosityCurve curveInaccurateGas25C(double visc25c, double freezingtemp); // only for inaccurate situations, but filling in information when there is no graph data.
    static ViscosityCurve curveInaccurateLiquid25C(double visc25c, double freezingtemp);
};

#endif
