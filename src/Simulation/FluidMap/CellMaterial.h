#ifndef CELLMATERIAL_H_
#define CELLMATERIAL_H_

#include "../../Engineering/Physics/FluidMechanics/ViscosityCurve.h"

#ifndef BOILINGMATERIAL_H_
    #include "BoilingMaterial.hpp"
#else
    class BoilingMaterial;
#endif

// does not go too in-depth of a material. Only includes what is required for a solid/liquid to determine changes in pressure, etc.

// Cell Materials determine dynamic viscosity, boiling, heating points, etc.

// Water: Viscocity = (1.8 @ 0 Celcius), (1.0 @ 20 Celcius), (0.1 @ 350 Celcius)

enum MATTERSTATE {MATTERSTATE_LIQUID, MATTERSTATE_SOLID, MATTERSTATE_GAS, MATTERSTATE_PLASMA};


class CellMaterial{
private:
    ViscosityCurve viscosity; // refusal to change in pressure, decreases with temperature. (This is the value at the closest to freezing) Mu=A*e^(B/T)
    
    
    // temperature grades @ base pressure
    double melting; // if solid, phase change to liquid, freezing, desublimation point
    double boiling; // if liquid, phase change to gas, condensation point, sublimation point
    double vaporpressure; // for materials like mercury that just dont want to stay a liquid at sea level. (increases with temperature)
    double specific_heat; // joule/gram (4.186 water)
    double thermal_conductivity; // W/m Kelvin (0.6 water)
    MATTERSTATE state;
    
    LinkedList<BoilingMaterial> materials;
    
public:
    CellMaterial(){}
    CellMaterial(MATTERSTATE state, double melting, double boiling);
    CellMaterial(MATTERSTATE state, double melting, double boiling, double specific_heat, double thermal_conductivity);
    CellMaterial(MATTERSTATE state, double melting, double boiling, ViscosityCurve viscosity);
    CellMaterial(MATTERSTATE state, double melting, double boiling, double specific_heat, double thermal_conductivity, ViscosityCurve viscosity);
    virtual ~CellMaterial();
    
    void setViscosity(ViscosityCurve viscosity); // required for simulation, just input list of kelvin+viscosity to get a curve
    
    // advanced boiling materials, like crude oil or Alcohol to a variety of gasses, liquids and solids.
    // salt water into salt, water
    // polluted water into dirt, water
    void setBoilingMaterials(LinkedList<BoilingMaterial> mats);
};

#endif
