#include "FluidCell2D.h"


FluidCell2D::FluidCell2D(int x, int y){
    initcell();
    this->x=x;
    this->y=y;
}

FluidCell2D::FluidCell2D(int x, int y, float volume){
    initcell();
    this->x=x;
    this->y=y;
    this->volume = volume;
}

// all known values
FluidCell2D::FluidCell2D(int x, int y, CellMaterial* material, float volume, float pressure, float temperature){
    initcell();
    this->x=x;
    this->y=y;
    this->material=material;
    this->volume = volume;
    this->pressure = pressure;
    this->temperature = temperature;
}

// unknown temperature
FluidCell2D::FluidCell2D(int x, int y, CellMaterial* material, float volume, float pressure){
    initcell();
    this->x=x;
    this->y=y;
    this->material=material;
    this->volume = volume;
    this->pressure = pressure;
}
