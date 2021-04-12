#ifndef FLUIDCELL2D_H_
#define FLUIDCELL2D_H_

#include "FluidCell.h"

// derived from FluidCell, just includes coordinates
class FluidCell2D : private FluidCell{
public:
    int x,y;
    FluidCell2D(int x, int y);
    FluidCell2D(int x, int y, float volume);
    FluidCell2D(int x, int y, CellMaterial* material, float volume, float pressure, float temperature); // all known values
    FluidCell2D(int x, int y, CellMaterial* material, float volume, float pressure); // unknown temperature
    
    void simulate(FluidCell*** map);
};

#endif
