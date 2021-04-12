#include "FluidCell.h"


// set base unknown values
void FluidCell::initcell(){
    temperature=0; // kelvin: 0.
    volume=1; // volume tends to be given by the FluidMap as a set value: 1 meter^3.
    pressure=0; // pascal: 0
    
    // material
    CellMaterial* material=0x0;
}


// vacuum of all unknowns
FluidCell::FluidCell(){
    initcell();
}

// initializes a vacuum with a set value
FluidCell::FluidCell(float volume){
    initcell();
    this->volume = volume;
}

// all known values
FluidCell::FluidCell(CellMaterial* material, float volume, float pressure, float temperature){
    this->material=material;
    this->volume = volume;
    this->pressure = pressure;
    this->temperature = temperature;
}

// unknown temperature
FluidCell::FluidCell(CellMaterial* material, float volume, float pressure){
    initcell();
    
    this->material=material;
    this->volume = volume;
    this->pressure = pressure;
}

void FluidCell::setMaterial(CellMaterial* material){
    this->material=material;
}
