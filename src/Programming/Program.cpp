#include "Program.h"

Program::Program(int inslots, int actionslots, int outslots) {
    head = 0x0;
    inputs = (DynamicType*) calloc(inslots,sizeof(DynamicType));
    actions = (DynamicType*) calloc(outslots,sizeof(DynamicType));

    outputs = (void(*)(DynamicType *)) calloc(actionslots, sizeof(void(*)(DynamicType*)));

    this->inslots = inslots;
    this->actionslots = actionslots;
    this->outslots = outslots;
}


// Tests for either textual or graphical program.
ProgramError* Program::tick() {
    ProgramError* error = (ProgramError*)(new VProgramError(PE_None,0));
    switch(ptype) {
        case PTX_Graphical:
            error = tickGNode(head, (VProgramError*)error); // Continued on "Visual/VisualProgram.cpp"
            break;
        case PTX_Textual:
            //
            break;
    }

    runs++;

    return error;
}
