#ifndef FSM_NODE_H_
#define FSM_NODE_H_

#include "../../GenericAINode.h"

// The FSM Node is basically just a pass-through node.


// Memory cost:
//  32-bit processor = 4 bytes
//  64-bit processor = 8 bytes
class FSM_Node : public GenericAINode{
public:
    FSM_Node();

    
    // no variable inputs matter here.
    FSM_Node* tick(){
        // Just a pass-through
        return outputnode;
    }
    
    // if this is 0x0, do nothing.
    FSM_Node* outputnode; 
};

#endif
