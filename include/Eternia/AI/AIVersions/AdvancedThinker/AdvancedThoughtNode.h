#ifndef ADV_THOUGHT_NODE_H_
#define ADV_THOUGHT_NODE_H_

#include "../../GenericAI.h"
#include "../../GenericVariable.h"
#include "../../GenericAINode.h"
#include "../../Interface/AIInterface.h"
#include "../../AITickOutput.h"

enum ATNOP{ATN_NONE, ATN_ADD, ATN_DIVIDE, ATN_SUB, ATN_SIN, ATN_MUL, ATN_MOD};

class AdvancedThoughtNode : public GenericAINode{

public:
    AdvancedThoughtNode *next;
    ATNOP operation;
    
    AdvancedThoughtNode();
    AdvancedThoughtNode(ATNOP operation);
    virtual ~AdvancedThoughtNode();
    
    
    AITickOutput tick(double second, GenericVariable* directvar, AIInterface* interface);

};

#endif
