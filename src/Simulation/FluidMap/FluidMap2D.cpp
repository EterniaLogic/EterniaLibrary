#include "FluidMap2D.h"

FluidMap2D::FluidMap2D(float _cellsize, int _width, int _height){
    this->cellsize = _cellsize;
    this->width = _width;
    this->height = _height;
    this->edge = FM_EDGEVACUUM; // assume that the edges are a vacuum
    
    map = (FluidCell2D***)malloc(_width*sizeof(FluidCell2D**));
    for(int i=0; i<_width; i++) {
        map[i] = (FluidCell2D**)malloc(_height*sizeof(FluidCell2D*));
    }
    
    
    // fill map with a vacuum
    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            double cs = cellsize;
            map[x][y] = new FluidCell2D(x,y,std::pow(cs,3.0));
        }
    }
}

FluidMap2D::~FluidMap2D() {}

void FluidMap2D::simulate(double timeseconds){
    // fluid cells will pressurize-depressurize depending on local cells.
    // fluid cells equalize evenly between all touching and diagonal cells
    // select random
}
