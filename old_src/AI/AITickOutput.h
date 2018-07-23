#ifndef THINKER_TICK_OUTPUT_H_
#define THINKER_TICK_OUTPUT_H_

#include "GenericAINode.h"
#include "GenericVariable.h"

// Basically just a list with a an AI Node and a passed variable
class AITickOutput{
public:
    AITickOutput(GenericAINode* node, GenericVariable* passedvar){
        this->node = node;
        this->passedvar = passedvar;
    }
    
    GenericAINode* node;
    GenericVariable* passedvar;
};


#endif
