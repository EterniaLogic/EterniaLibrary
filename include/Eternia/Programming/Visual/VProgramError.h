#ifndef VPROGRAM_ERROR_H_
#define VPROGRAM_ERROR_H_

#include "../ProgramError.h"

enum PEType {PE_None, PE_TypeError1, PE_TypeError2, PE_NoInput};

class VProgramError : public ProgramError {
    public:
        VProgramError(PEType t, int node);

        PEType type;
        int nodeid; // node which caused the error
};

#endif
