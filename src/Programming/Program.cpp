#include "Program.h"

Program::Program(int inslots, int actionslots, int outslots) {
    head = 0x0;
    inputs = (VProgramVariable*) calloc(inslots,sizeof(VProgramVariable));
    actions = (VProgramVariable*) calloc(outslots,sizeof(VProgramVariable));

    outputs = (void(*)(VProgramVariable *)) calloc(actionslots, sizeof(void(*)(VProgramVariable*)));

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
