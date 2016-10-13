#ifndef PROGRAM_VARIABLE_H_
#define PROGRAM_VARIABLE_H_

#include "../../Data/CharString.h"

enum PV_Type {PV_None, PV_Number, PV_String, PV_Object};
// PV_Object is used for special purposes, like items

// Variable for a graphical program
class VProgramVariable {
    public:
        VProgramVariable();

        PV_Type type;
        CharString name; // name of the variable
        CharString string; // string value of this variable
        double number;
        void* object; // object set as a variable
};

#endif
