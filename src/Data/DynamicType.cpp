#include "DynamicType.h"

DynamicType::DynamicType(){
    data = 0x0;
    tsize=0; // used for classes
    _type=DT_NONE;
}

void DynamicType::setZero(){
    data = calloc(1,sizeof(double));
    *((double*)data) = 0.0;
    _type = DT_DOUBLE;
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



bool DynamicType::isNumber(){
    return (_type == DT_CHAR || _type == DT_UCHAR ||
            _type == DT_SHORT || _type == DT_USHORT ||
            _type == DT_INT || _type == DT_UINT ||
            _type == DT_LONG || _type == DT_ULONG ||
            _type == DT_FLOAT || _type == DT_DOUBLE);
}

bool DynamicType::isString(){
    return (_type == DT_CHAR || _type == DT_STRING);
}

bool DynamicType::isClass(){
    return (_type == DT_CLASS);
}


