#ifndef BOILINGMATERIAL_H_
#define BOILINGMATERIAL_H_

#ifndef CELLMATERIAL_H_
    #include "CellMaterial.h"
#else
    class CellMaterial;
#endif


// includes the boiling point of a material and the resultant CellMaterial

class BoilingMaterial{
public:
    float boilingpoint; // point at which this is boiled out of a liquid
    float percentage; // percent of boiling product as this material
    CellMaterial* material;
    BoilingMaterial(float boilingpoint, float percentage, CellMaterial* material){
        this->boilingpoint = boilingpoint;
        this->percentage = percentage;
        this->material = material;
    }
};

#endif
