#include "IAnimated.h"

IAnimated::IAnimated(){
    maxFrames=1;
    currentFrame=0;
    timepassed=0;
}

IAnimated::~IAnimated(){}


void IAnimated::animateTick(long timeMillis){
    
}
