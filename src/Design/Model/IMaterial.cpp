#include "IMaterial.h"

IMaterial::IMaterial(){
    AmbientColor=NULL_VERTEX;
    DiffuseColor=NULL_VERTEX;
    SpecularColor=NULL_VERTEX;
    EmitColor=NULL_VERTEX;
    ModelColor=NULL_VERTEX;
    
    ColorMap=0x0;
    DiffuseMap=0x0;
    SpecularMap=0x0;
    EmitMap=0x0;
    AlphaMap=0x0;
    BumpMap=0x0;
    ShinyMap=0x0;
    MirrorMap=0x0;
}
