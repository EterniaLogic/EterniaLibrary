#include "DynamicType.h"

DynamicType::DynamicType(){
    data = 0x0;
    tsize=0;
    type=DT_NONE;
}
    
// get raw value (must be casted)
void* DynamicType::get(){
    return data;
}

// get type size
int DynamicType::getSize(){
    return tsize;
}

// get inferred type
DTType DynamicType::getType(){
    return type;
}

DynamicType DynamicType::operator =(void* c){ 
    data = c;
    tsize = sizeof(c);
    type = DT_CLASS;
}
