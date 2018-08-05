#include "DynamicType.h"

DynamicType::DynamicType(){
    data = 0x0;
    tsize=0;
    _type=DT_NONE;
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
    return _type;
}

DynamicType DynamicType::operator =(void* c){ 
    data = c;
    tsize = sizeof(c);
    _type = DT_CLASS;
}
