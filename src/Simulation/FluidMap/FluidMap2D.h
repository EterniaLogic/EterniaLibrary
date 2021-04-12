#ifndef TPMAP2D_H_
#define TPMAP2D_H_

#include "../CEntity.h"
#include "../../Data/includes.h"
#include "FluidCell2D.h"
#include <malloc.h>

// a 2D map that includes fluid, temperature and pressure dynamics
// NOTE: This also includes solids in cells, but they will not have obvious pressure dynamics

enum FM_EDGEACTION {FM_EDGESOLID, FM_EDGEVACUUM};

class FluidMap2D : public CEntity{
private:
    float cellsize; // size in side-length, meters
    int width, height;
    
    FluidCell2D*** map; // rarely get to use triple-star references would be quadruple-star for a 3D map. [x][y]
    FM_EDGEACTION edge; // is the edge of map a solid or a vacuum that infinitely sucks up gases and liquids?
public:
    // cellsize is in the length in meters of one of the sides of a cube, defines how accurate temperature map is. (Games tend to use 1 meter as it is simple but inaccurate, like OxygenNotIncluded)
    // initializes 2D vector map
    FluidMap2D(float cellsize, int width, int height);
    virtual ~FluidMap2D();
    
    FluidCell2D* getCell(int x, int y); // 0 -> (width-1), else returns NULL
    void setCell(int x, int y, FluidCell2D* cell); // better to get() and change that, but this is an option.
    
    
    // simulate!
    // fluid cells will pressurize-depressurize depending on local cells.
    void simulate(double timeseconds);
};

#endif
