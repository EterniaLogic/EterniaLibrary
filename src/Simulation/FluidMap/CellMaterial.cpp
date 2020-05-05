#include "CellMaterial.h"


CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
}

CellMaterial::CellMaterial(MATTERSTATE state, double melting, double boiling, ViscosityCurve viscosity){
    this->state = state;
    this->melting = melting;
    this->boiling = boiling;
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
