#include "Location.h"


Location::Location(double _x, double _y, double _z, double _dimension) {
    x=_x;
    y=_y;
    z=_z;
    dim=_dimension;
    
    setupSerialization();
}

Location::Location(double _x, double _y, double _z) {
    x=_x;
    y=_y;
    z=_z;
    dim=0;
    
    setupSerialization();
}

Location::Location() {
    x=y=z=dim=0;
    setupSerialization();
}

void Location::setupSerialization(){
    addSerial(&x,"x",SSE_double);
    addSerial(&y,"y",SSE_double);
    addSerial(&z,"z",SSE_double);
    addSerial(&dim,"dimension",SSE_double);
}
