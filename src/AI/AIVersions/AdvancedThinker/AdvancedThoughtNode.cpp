#include "AdvancedThoughtNode.h"

AdvancedThoughtNode::AdvancedThoughtNode(){
    next = 0x0;
    operation = ATN_NONE;
}

AdvancedThoughtNode::~AdvancedThoughtNode(){}

AITickOutput AdvancedThoughtNode::tick(double second, GenericVariable* directvar, AIInterface* interface){
    // determine path(s) to go on.
    // AKA:
    //      isDark => One node
    //      
}
