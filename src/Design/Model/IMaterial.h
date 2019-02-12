#ifndef MTLMATERIAL_H_
#define MTLMATERIAL_H_

#include "../../Math/struct/vertex.h"
#include "../../Data/CharString.h"
#include "../IAnimated.h"

class IMaterial{
public:
    IMaterial();
    ~IMaterial(){}

    CharString name;

    // direct values
    Math::vertex AmbientColor, DiffuseColor, SpecularColor, EmitColor, ModelColor;

    double Shininess, Alpha;
    short Illumination; // illumination model

    // 2D cubic Maps, not the job of this library to load them.
    CharString ColorMap_loc, DiffuseMap_loc, SpecularMap_loc, EmitMap_loc, AlphaMap_loc, BumpMap_loc, ShinyMap_loc, MirrorMap_loc;
    IAnimated *ColorMap, *DiffuseMap, *SpecularMap, *EmitMap, *AlphaMap, *BumpMap, *ShinyMap, *MirrorMap;
};

#endif
