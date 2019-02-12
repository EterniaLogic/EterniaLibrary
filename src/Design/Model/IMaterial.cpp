#include "IMaterial.h"

IMaterial::IMaterial(){
    AmbientColor=NULL_VERTEX;
    DiffuseColor=NULL_VERTEX;
    SpecularColor=NULL_VERTEX;
    EmitColor=NULL_VERTEX;
    ModelColor=NULL_VERTEX;
    ColorMap = 0x0;
    DiffuseMap = 0x0;
    SpecularMap = 0x0;
    AlphaMap = 0x0;
    ShinyMap = 0x0;
    BumpMap = 0x0;
    EmitMap = 0x0;
    MirrorMap = 0x0;
}

void IMaterial::animateTick(long timeMillis){
    // tick all images
    if(ColorMap != 0x0 && ColorMap->isLoaded()) ColorMap->animateTick(timeMillis);
    if(DiffuseMap != 0x0 && DiffuseMap->isLoaded()) DiffuseMap->animateTick(timeMillis);
    if(SpecularMap != 0x0 && SpecularMap->isLoaded()) SpecularMap->animateTick(timeMillis);
    if(AlphaMap != 0x0 && AlphaMap->isLoaded()) AlphaMap->animateTick(timeMillis);
    if(ShinyMap != 0x0 && ShinyMap->isLoaded()) ShinyMap->animateTick(timeMillis);
    if(BumpMap != 0x0 && BumpMap->isLoaded()) BumpMap->animateTick(timeMillis);
    if(EmitMap != 0x0 && EmitMap->isLoaded()) EmitMap->animateTick(timeMillis);
    if(MirrorMap != 0x0 && MirrorMap->isLoaded()) MirrorMap->animateTick(timeMillis);
}
