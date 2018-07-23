#ifndef FSM_AI_H_
#define FSM_AI_H_

#include "FSM_Node.h"
#include "../../GenericAI.h"
#include "../../../Data/LinkedList.hpp"
#include "../../Interface/AIInterface.h"

// The FSM_AI is a somewhat more intelligent intelligent system.
// The emphasis on this AI is cross-connecting pre-specified nodes.


// Attributes:
/*
    * Local variables are never used
    * Inputs and outputs are ONLY boolean. (Non-boolean values will be ignored)
    * Every input/output has acts like a node, where the value is only boolean.
    * Action slots are only used when outputing.
    * Action slot parameter output is only a boolean.  void action(bool value)
    * If an action slot is not triggered at the end of a tick, the bool value will be false.
    * Nodes are used.
    * Nodes my have infinite inputs.
    * Nodes may only have 1 output.
    * inputs can only be boolean types
    
    * Errors that are considered during generation/self-evolve:
        * loopback nodes (infinite loops on single node)
        * multi-node loop (infinite loops on several nodes)
*/


// A good example for this idea is:
// http://doublezoom.free.fr/programmation/AG_Exemple_Fighting.php



// upon "Death" from evolution, all this FSM does is re-run Generate.

class FSM_AI : public GenericAI{
public:
    LinkedList<FSM_Node> innernodes; // nodes are saved, otherwise the nodes would be lost when they have no connections.
    LinkedList<FSM_Node> inputnodes; // initial nodes for each input. (loop through them)
    LinkedList<FSM_Node> outputnodes; // initial nodes for each input. (loop through them)
    AIInterface* interface; // interface to provide stimulus and perform actions.

    FSM_AI(AIInterface* interface); // initialize with the interface (controls and input)

    void Generate(int maxnodes); // Generate random thought map, only used when seeding a population.
    void tick(double second);  // seconds are irrelevant here. Tick through all i/o nodes
    float GetEfficiency(); // get # of nodes that this thinker uses. (Higher # of nodes will decrease score)
    GenericAI* Breed(GenericAI* other); // cross-breed with another AI
    bool BadOutput();
    // Self evolution, plays around with the interconnected links.
    void SelfEvolve();
};


// The memory generated from this FSM_AI can probably be exported and placed onto a FPGA.
#endif
