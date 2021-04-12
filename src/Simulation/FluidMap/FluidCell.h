#ifndef FLUIDCELL_H_
#define FLUIDCELL_H_

#include "../../Engineering/Physics/FluidMechanics/FluidBaseEquations.h"
#include "../../Data/includes.h"
#include "CellMaterial.h"

// Fluid Cells include temperature, volume and pressures. Any change in either will change the other values.
// Temperature in Kelvin, Volume in Liters, Pressure in Pascals.

// using floats due to size constraints

class FluidCell{
protected:
    float temperature; // kelvin: 0.
    float volume; // volume tends to be given by the FluidMap as a set value: 1 meter^3.
    float pressure; // pascal: 0
    
    // material
    CellMaterial* material;
    // LinkedList<>   // Layer
public:
    FluidCell(); // vacuum of all unknowns
    FluidCell(float volume); // initializes a vacuum with a set value
    FluidCell(CellMaterial* material, float volume, float pressure, float temperature); // all known values
    FluidCell(CellMaterial* material, float volume, float pressure); // unknown temperature
    
    void initcell(); // set base unknown values as perfect vacuum.
    
    void setMaterial(CellMaterial* material);
    
    
    void interact(); // interact with neighbor cells. (gravity and direction are important, if no gravity, assumed in space so perhaps liquid will not flow)
};

#endif
