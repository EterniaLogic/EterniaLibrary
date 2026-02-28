#include "../Program.h"

// Run program
VProgramError* Program::tickGNode(VProgramNode* node, VProgramError* error) {
    // loop through program
    DynamicType* v1;
    DynamicType* v2;
    int var1;
    int var2;
    int var3;
    VarTYPE var1slot;
    VarTYPE var2slot;
    VarTYPE var3slot;
    DynamicType* p = new DynamicType();
    *p = 0.0;

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
                if(getVariable(var1, var1slot)->getType() == DT_NONE) {
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
                    } else repeatval = (int)getVariable(var1, var1slot)->getDouble();

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
                if(!v1->isNumber()) {
                    error->type = PE_TypeError1;
                    error->nodeid = current->nodeid;
                    return error;
                }
                if(!v2->isNumber()) {
                    error->type = PE_TypeError2;
                    error->nodeid = current->nodeid;
                    return error;
                }


                p->setZero();

                switch(current->mtype) {
                    case MT_Sub: // var3 = var1 - var2
                        *p = (*v1)-(*v2);
                        break;
                    case MT_Add: // var3 = var1 + var2
                        *p = (*v1)+(*v2);
                        break;
                    case MT_Mul: // var3 = var1 * var2
                        *p = (*v1)*(*v2);
                        break;
                    case MT_Div: // var3 = var1 / var2
                        *p = (*v1)/(*v2);
                        break;
                    case MT_Mod: // var3 = var1 & var2
                        *p = fmod(v1->getDouble(), v2->getDouble());
                        break;
                    case MT_Exponent: // var3 = var1 ^ var2
                        *p = Math::pow(v1->getDouble(), v2->getDouble());
                        break;
                }

                setVariable(var3, var3slot, p);

                break;
            case NT_Set: // Set a variable
                setVariable(var2, var2slot, v1);
                break;
            case NT_Output: // Output value function
                void (*func1)(DynamicType*) = outputs[var1];

                if(func1 != 0x0) {
                    func1(getVariable(var2, var2slot));
                }

                break;
        }


        current = current->ifnode;
    }

    return 0x0;
}

// get a specific variable from inputs or locals
DynamicType* Program::getVariable(int slot, VarTYPE typex) {
    switch(typex) {
        case VAT_IN:
            return &(inputs[slot]);
            break;
        case VAT_LOCAL:
            return locals.get(slot);
            break;
    }

    return 0x0;
}

// set a specific variable from inputs or locals
DynamicType* Program::setVariable(int slot, VarTYPE typex, DynamicType* var) {
    DynamicType* vx = locals.get(slot);
    switch(typex) {
        case VAT_IN:
            inputs[slot] = *var;
            break;
        case VAT_LOCAL:
            *vx = *var;
            break;
    }

    return 0x0;
}

// compare these values for a conditional
bool Program::compareVars(VProgramNode* node) {
    DynamicType* v1 = getVariable(node->var1, node->var1slot);
    DynamicType* v2 = getVariable(node->var2, node->var2slot);

    // both types do not match?
    if(v1->getType() != v2->getType()) return false;


    if(v1->isNumber()) {
        double v1d = v1->getDouble();
        double v2d = v2->getDouble();
        switch(node->ctype) {
            case PCC_Equals:
                if(v1d == v2d) return true;
                break;
            case PCC_Greater:
                if(v1d > v2d) return true;
                break;
            case PCC_GreaterEq:
                if(v1d >= v2d) return true;
                break;
            case PCC_Less:
                if(v1d < v2d) return true;
                break;
            case PCC_LessEq:
                if(v1d <= v2d) return true;
                break;
        }
    } else if(v1->getType() == DT_STRING && node->ctype == PCC_Equals) {
        if(v1->getString().compare(v2->getString())) return true;
    } else if(v1->getType() == DT_CLASS && node->ctype == PCC_Equals) {
        if(v1->get() == v2->get()) return true;
    }

    return false;
}

// Load program nodes
void Program::loadNodes(CharString* nodelist) {

}

// sets the value of a variable
void Program::input(int slot, DynamicType* var) {
    inputs[slot] = *var;
}

// Reset an input slot
void Program::resetInput(int slot) {
    inputs[slot].setZero();
}
