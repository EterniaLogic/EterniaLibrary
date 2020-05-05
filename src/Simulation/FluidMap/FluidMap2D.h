#ifndef TPMAP2D_H_
#define TPMAP2D_H_

#include "../CEntity.h"
#include "../../Data/includes.h"
#include "FluidCell2D.h"

// a 2D map that includes fluid, temperature and pressure dynamics
// NOTE: This also includes solids in cells, but they will not have obvious pressure dynamics

class FluidMap2D : public CEntity{
private:
    float cellsize;
    int width, height;
public:
    // cellsize is in meters, defines how accurate temperature map is. (Games tend to use 1 meter as it is simple but inaccurate, like OxygenNotIncluded)
    // initializes 2D vector map
    FluidMap2D(float _cellsize, int _width, int _height);
    virtual ~FluidMap2D();
    
    FluidCell2D* getCell(int x, int y); // 0 -> (width-1), else returns NULL
    void setCell(int x, int y, FluidCell2D* cell); // better to get() and change that, but this is an option.
};

#endif
