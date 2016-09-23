#include "VProgramError.h"


VProgramError::VProgramError(PEType t, int node){
    this->type = t;
    this->nodeid = node;
}
