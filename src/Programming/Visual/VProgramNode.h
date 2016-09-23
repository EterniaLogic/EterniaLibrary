#ifndef VPROGRAM_NODES_H_
#define VPROGRAM_NODES_H_

// Data structure
enum PNodeType{NT_None, NT_Cond, NT_Input, NT_Output, NT_Set, NT_Math, NT_Dispplay};
enum PCondCompare{PCC_None, PCC_Equals, PCC_Greater, PCC_GreaterEq, PCC_Less, PCC_LessEq};
enum PMathType{MT_None, MT_Add, MT_Sub, MT_Mul, MT_Div, MT_Mod, MT_Exponent};
enum VarTYPE {VAT_None, VAT_IN, VAT_LOCAL}; // select a variable channel
// Conditional nodes can repeat up to N number of times.

class VProgramNode{
public:
    VProgramNode(CharString* val);
    VProgramNode();
    
    VProgramNode* ifnode; // next node if not conditional
    VProgramNode* elsenode; // else next node (conditional)
    
    bool repeating; // is this node repeating? (like a for loop, conditional)
    
    int nodeid; // node id, useful for error debugging
    
    int slot; // slot for input/output
    int var1, var2, var3; // slot locations for vars
    VarTYPE var1slot, var2slot, var3slot;
    int const_loops; // number of times to loop if conditional
    
    PNodeType type; // type of node, conditional
    PMathType mtype; // type of math to perform
    PCondCompare ctype; // Comparison type, for if/else statements
};

#endif
