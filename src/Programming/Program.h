#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "../Data/includes.h"
#include "Visual/VProgramNode.h"
#include "Visual/VProgramError.h"
//#include "Visual/VProgramVariable.h"
#include "../Math/Math.h"
#include <cstdlib>
#include <math.h>

// A program is a script that enables for all forms of development for unique parts.
// These programs are important for how the building, ship or vehicle works.

// This is also run either on the master servers or client public nodes.
// Programs have enforced tick rates for processing.
// Programs can be executed with the EventHandler.

// Graphical-based programs are drag-drop, like easyC.

// WaitInput (Item)     -  Test an input if it exists
// Output (Item)        -  Output value
// Display (Variable)   -  Display variable on a screen
// Conditional          -  (Variable, repeat variable or repeat constant)
// Action (Variable)    -  Action to perform

enum ProgTYPE {PTX_Graphical, PTX_Textual};

class Program {
    public:
        Program(int inslots, int actionslots, int outslots);

        ProgTYPE ptype;
        int loops; // Number of times a conditional has looped.
        ProgramError* tick(); // Run program from Head (Or textual)


        // Visual parts
        DynamicType *inputs, *actions;
        void (*outputs)(DynamicType*);
        int inslots, actionslots, outslots;

        LinkedList<DynamicType*> locals; // Local variables for the program.
        void (*display)(DynamicType*); // display to show info. (Either debugger or something else)
        int runs; // number of times this was executed.
        VProgramNode* head; // First graphical node
        int nodeidinc; // increments every time a node is added

        VProgramError* tickGNode(VProgramNode*,VProgramError*);
        void loadNodes(CharString* nodelist); // Load program nodes
        void input(int slot, DynamicType* value); // sets the value of a variable
        void resetInput(int slot); // Reset an input slot
        DynamicType* getVariable(int slot, VarTYPE typex);
        DynamicType* setVariable(int slot, VarTYPE typex, DynamicType* var);
        bool compareVars(VProgramNode* node);
};

#endif
