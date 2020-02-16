#include "IMaterial.h"

IMaterial::IMaterial(){
    AmbientColor=NULL_VERTEX;
    DiffuseColor=NULL_VERTEX;
    SpecularColor=NULL_VERTEX;
    EmitColor=NULL_VERTEX;
    ModelColor=NULL_VERTEX;
    Illumination=0.0;
    Alpha=0.0;
    Shininess=0.0;
    

    ColorMap=0x0;
    DiffuseMap=0x0;
    SpecularMap=0x0;
    EmitMap=0x0;
    AlphaMap=0x0;
    BumpMap=0x0;
    ShinyMap=0x0;
    MirrorMap=0x0;

}

IMaterial::~IMaterial(){}
