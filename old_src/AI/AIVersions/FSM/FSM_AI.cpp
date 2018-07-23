#include "FSM_AI.h"

// initialize with the interface (controls and input)
FSM_AI::FSM_AI(AIInterface* interface){}

// Generate random thought map, only used when seeding a population or "deleting" from population.
void FSM_AI::Generate(int maxnodes){
    
}

// seconds are irrelevant here. Tick through all i/o nodes
void FSM_AI::tick(double second){
    FSM_Node *node;
    GenericVariable* var;
    int i;
    void (*action)(GenericVariable*);
    
    /*// Loop through inputs, determine if an input is on or not.
    for(i=0; i<interface->inputs.size();i++){
        node = inputnodes.get(i);
        var = interface->inputs.get(i);
        
        if(var != 0x0 && node != 0x2){
            if(node != 0x0){
                // tick this node
                while(node != 0x0){
                    if(node.outputnode == 0x1) node.outputnode = 0x2;
                    node = node->tick();
                }
            }else{
                inputnodes.add(new FSM_Node());
            }
        }
    }
    
    // Loop through output nodes.
    for(i=0; i<interface->actions.size();i++){
        node = outputnodes.get(i);
        action = interface->actions.get(i);
        if(action != 0x0){
            if(node != 0x0){
                if(node == 0x1){
                    action(trueval); // execute output function
                }else if(node == 0x2){
                    action(falseval); // execute output function
                }
                
            }else{
                // create a new output node since an action was added here.
                // no point in ticking it yet, since there are no interconnections made yet.
                node = new FSM_Node();
                node.outputnode = 0x1; // only output nodes get illegal addresses.
                outputnodes.add(node);
            }
        }else{
            // was there an action node removed?
        }
    }*/
} 

// get # of nodes that this thinker uses. (Higher # of nodes will decrease score)
float FSM_AI::GetEfficiency(){
    
}

// cross-breed with another FSM AI
GenericAI* FSM_AI::Breed(GenericAI* other){
    
}

// Self evolution, plays around with the interconnected links.
void FSM_AI::SelfEvolve(){
    
}

bool FSM_AI::BadOutput(){
    return false;
}
