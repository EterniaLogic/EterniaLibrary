#ifndef ADVTHINKER_H_
#define ADVTHINKER_H_

#include "../../GenericAI.h"
#include "../../Interface/AIInterface.h"
#include "../../AITickOutput.h"
#include "AdvancedThoughtNode.h"


// CPU-like AI nodes. 
// Any evolution from this will be fairly stupid at first, but extremely powerful later on.


// Attributes:
/*
    * CPU-like nodes, each has an Opcode and executions on every node.
    * Local variables may be written, read, deleted.
    * Inputs and outputs can be any variable type.
    
    * CPU and memory heavy depending on the opcode for each node.
    
    * Nodes can jump to any other node on a jump Opcode.
    * Nodes can pass variables to the next node.
    
    * Errors are considered on re-generation.
        * A node instruction that requires a numeric input will not pair up with an instruction that outputs an image.
        * This may help self-evolution.
*/

class AdvancedThinker : public GenericAI{
public:
    int numNodes; // number of nodes generated so far
    LinkedList<AdvancedThoughtNode> startNodes; // starting nodes, uses AIInterface for input values
    LinkedList<AdvancedThoughtNode> endNodes; // ending nodes, uses AIInterface for output function
    LinkedList<AdvancedThoughtNode> nodes; // used for a jump instruction
    AIInterface* interface; // interface to provide stimulus and perform actions.

    AdvancedThinker(AIInterface* interface, int inputs, int outputs, int internalNodes); // initialize with the interface (controls and input)
    virtual ~AdvancedThinker();
    
    void Generate(int maxnodes); // Generate random thought map, only used when seeding a population.
    void tick(double second);  // perform actions from the nodal map.
    float GetEfficiency(); // get # of nodes that this thinker uses. (Higher # of nodes will decrease score)
    GenericAI* Breed(GenericAI* other); // breed attributes with another AI
    void SelfEvolve();
    bool BadOutput(); // 
    
    
    // functions for self-evolving AIs.
    void ScanInputs(); // Scan the inputs for any changes, if a change assign some nodes for it.
    void PlayOutputs(); // play around with outputs
    void PlayActions(); // play with actions
    
    // Specific functionality for specialty AI programs
    // This could include external systems that have very specific classes.
    void (*tickSpecialNodes)(double second);
};

#endif
