#include "AdvancedThinker.h"


 // initialize with the interface (controls and input)
AdvancedThinker::AdvancedThinker(AIInterface* interface, int inputs, int outputs, int internalNodes){
    for(int i=0;i<inputs;i++) startNodes.add(new AdvancedThoughtNode());
    for(int i=0;i<outputs;i++) endNodes.add(new AdvancedThoughtNode());
    for(int i=0;i<internalNodes;i++) nodes.add(new AdvancedThoughtNode());
}

AdvancedThinker::~AdvancedThinker(){
    startNodes.clear();
    endNodes.clear();
    nodes.clear();
}


// combine the nodal traits with another thinker.
// variables are also breeded
GenericAI* AdvancedThinker::Breed(GenericAI* other){

}

// Generate random thought map, only used when seeding a population.
//  This version of thinkers uses nodes.
//  Some other thinker versions may just have a set of given variables, which may
//  be useful for pre-programmed creatures or objects that fully requires genetic manipulation.
void AdvancedThinker::Generate(int maxnodes){
    int numnodes; // randomly generate # of nodes from min to max
}

// perform actions from the nodal map.
void AdvancedThinker::tick(double second){
    // This will tick exactly one of the nodes. 
    // If current is empty, goto the first node.
    
    for(int i=0;i < startNodes.getSize();i++){
        startNodes[i].tick(second, interface->getInput(i), interface);
    }
    
    // tick this node with a seconds (or sub-seconds), passed variable and the interface
/*    AITickOutput outx = current->tick(second, directvar, interface);
    current = (AdvancedThoughtNode*)outx.node; // thinkernode decides what the next node is.
    directvar = outx.passedvar; // passedvar is only used if required by the next node.*/
}

// get # of nodes that this thinker uses. (Higher # of nodes will decrease score)
float AdvancedThinker::GetEfficiency(){
    if(numNodes <= 0) return 1;
    return 1/numNodes; // basic score output, exponential functions might be useful here.
}


// functions for self-evolving AIs.
void AdvancedThinker::SelfEvolve(){
    
}

bool AdvancedThinker::BadOutput(){
    return false;
}

// Scan the inputs for any changes, if a change assign some nodes for it.
void AdvancedThinker::ScanInputs(){

}

// play around with outputs
void AdvancedThinker::PlayOutputs(){

}

// play with actions
void AdvancedThinker::PlayActions(){

} 
