#include "../Program.h"

// Run program
VProgramError* Program::tickGNode(VProgramNode* node, VProgramError* error) {
    // loop through program
    VProgramVariable* v1;
    VProgramVariable* v2;
    int var1;
    int var2;
    int var3;
    VarTYPE var1slot;
    VarTYPE var2slot;
    VarTYPE var3slot;
    VProgramVariable* p = new VProgramVariable();

    VProgramNode* current = node;
    // Loop through programming nodes
    while(current != 0x0) {
        v1 = getVariable(current->var1, current->var1slot);
        v2 = getVariable(current->var2, current->var2slot);
        var1 = current->var1;
        var2 = current->var2;
        var3 = current->var3;
        var1slot = current->var1slot;
        var2slot = current->var2slot;
        var3slot = current->var3slot;

        switch(current->type) {
            case NT_Input: // Test input
                if(getVariable(var1, var1slot)->type == PV_None) {
                    error->type = PE_TypeError1;
                    error->nodeid = current->nodeid;
                    return error;
                }
                break;
            case NT_Cond: // Test conditional, input or variable
                // Figure out what variable to use.

                // is this variable repeating?
                if(current->repeating) {
                    int repeatval = 0;
                    if(current->const_loops > 0) {
                        repeatval = current->const_loops;
                    } else repeatval = (int)getVariable(var1, var1slot)->number;

                    for(int i=0; i<repeatval; i++) {
                        return tickGNode(current->ifnode, error); // play the following loops!
                    }
                } else {
                    // goto else if the condition is false.
                    if(!compareVars(current)) {
//                            tickGNode(current->elsenode);
                        current = current->elsenode;
                        continue; // goto next while with the else node
                    }
                }
                break;
            case NT_Math: // Add, Sub, Mul, Div, Mod, Exponential
                if(v1->type != PV_Number) {
                    error->type = PE_TypeError1;
                    error->nodeid = current->nodeid;
                    return error;
                }
                if(v2->type != PV_Number) {
                    error->type = PE_TypeError2;
                    error->nodeid = current->nodeid;
                    return error;
                }


                p->type = PV_Number;

                switch(current->mtype) {
                    case MT_Sub: // var3 = var1 - var2
                        p->number = v1->number - v2->number;
                        break;
                    case MT_Add: // var3 = var1 + var2
                        p->number = v1->number + v2->number;
                        break;
                    case MT_Mul: // var3 = var1 * var2
                        p->number = v1->number * v2->number;
                        break;
                    case MT_Div: // var3 = var1 / var2
                        p->number = v1->number / v2->number;
                        break;
                    case MT_Mod: // var3 = var1 & var2
                        p->number = fmod(v1->number, v2->number);
                        break;
                    case MT_Exponent: // var3 = var1 ^ var2
                        p->number = Math::pow(v1->number, v2->number);
                        break;
                }

                setVariable(var3, var3slot, p);

                break;
            case NT_Set: // Set a variable
                setVariable(var2, var2slot, v1);
                break;
            case NT_Output: // Output value function
                void (*func1)(VProgramVariable*) = outputs[var1];

                if(func1 != 0x0) {
                    func1(getVariable(var2, var2slot));
                }

                break;
        }


        current = current->ifnode;
    }
}

// get a specific variable from inputs or locals
VProgramVariable* Program::getVariable(int slot, VarTYPE typex) {
    switch(typex) {
        case VAT_IN:
            return &(inputs[slot]);
            break;
        case VAT_LOCAL:
            return locals.get(slot);
            break;
    }
}

// get a specific variable from inputs or locals
VProgramVariable* Program::setVariable(int slot, VarTYPE typex, VProgramVariable* var) {
    VProgramVariable* vx = locals.get(slot);
    switch(typex) {
        case VAT_IN:
            inputs[slot].type = var->type;
            inputs[slot].number = var->number;
            inputs[slot].object = var->object;
            inputs[slot].string = var->string;
            break;
        case VAT_LOCAL:
            vx->type = var->type;
            vx->number = var->number;
            vx->object = var->object;
            vx->string = var->string;
            break;
    }
}

// compare these values for a conditional
bool Program::compareVars(VProgramNode* node) {
    VProgramVariable* v1 = getVariable(node->var1, node->var1slot);
    VProgramVariable* v2 = getVariable(node->var2, node->var2slot);

    // both types do not match?
    if(v1->type != v2->type) return false;


    if(v1->type == PV_Number) {
        switch(node->ctype) {
            case PCC_Equals:
                if(v1->number == v2->number) return true;
                break;
            case PCC_Greater:
                if(v1->number > v2->number) return true;
                break;
            case PCC_GreaterEq:
                if(v1->number >= v2->number) return true;
                break;
            case PCC_Less:
                if(v1->number < v2->number) return true;
                break;
            case PCC_LessEq:
                if(v1->number <= v2->number) return true;
                break;
        }
    } else if(v1->type == PV_String && node->ctype == PCC_Equals) {
        if(v1->string.Compare(&v2->string)) return true;
    } else if(v1->type == PV_Object && node->ctype == PCC_Equals) {
        if(v1->object == v2->object) return true;
    }

    return false;
}

// Load program nodes
void Program::loadNodes(CharString* nodelist) {

}

// sets the value of a variable
void Program::input(int slot, VProgramVariable* var) {
    inputs[slot].type = var->type;
    inputs[slot].number = var->number;
    inputs[slot].object = var->object;
    inputs[slot].string = var->string;
}

// Reset an input slot
void Program::resetInput(int slot) {
    inputs[slot].type = PV_None;
}
