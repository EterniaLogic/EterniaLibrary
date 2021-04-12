#include "CellMaterial.h"


CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
    this->specific_heat=1;
    this->thermal_conductivity=0.01;
    ViscosityCurve(1);
}

CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling, double specific_heat, double thermal_conductivity){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
    this->specific_heat = specific_heat;
    this->thermal_conductivity = thermal_conductivity;
    ViscosityCurve(1);
}

CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling, ViscosityCurve viscosity){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
    this->viscosity = viscosity;
    this->specific_heat=1;
    this->thermal_conductivity=0.01;
}


CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling, double specific_heat, double thermal_conductivity, ViscosityCurve viscosity){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
    this->specific_heat = specific_heat;
    this->thermal_conductivity = thermal_conductivity;
    this->viscosity = viscosity;
}

CellMaterial::~CellMaterial(){
    
}

void CellMaterial::setViscosity(ViscosityCurve viscosity){ // required for simulation, just input list of kelvin+viscosity to get a curve
    this->viscosity = viscosity;
}

// advanced boiling materials, like crude oil or Alcohol to a variety of gasses, liquids and solids.
// salt water into salt, water
// polluted water into dirt, water
void CellMaterial::setBoilingMaterials(LinkedList<BoilingMaterial> mats){
    this->materials = mats;
}
