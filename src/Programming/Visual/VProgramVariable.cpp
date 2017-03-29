#include "VProgramVariable.h"


VProgramVariable::VProgramVariable() {
    type = PV_None;
    name.set("DEFAULT_NAME"); // name of the variable
    string.set(""); // string value of this variable
    number = 0.0;
    object = 0x0; // object set as a variable
}
