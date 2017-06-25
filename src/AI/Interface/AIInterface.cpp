#include "AIInterface.h"

AIInterface::AIInterface(){
    
}
    
void AIInterface::addInput(GenericVariable *value){
    inputs.add(value);
}

void AIInterface::setInput(int id, GenericVariable *value){
    inputs[id] = value;
}

GenericVariable* AIInterface::getInput(int id){
    return inputs.get(id);
}


// standard Finite State Machine AI outputer
void AIInterface::addOutputFunction(void (*func)(GenericVariable*)){
    outputFuncs.add((unsigned int*)func);
}

void AIInterface::useOutput(int id, GenericVariable *v){
    if(outputFuncs.getSize() > id){
        void (*func)(GenericVariable*)  = (void (*)(GenericVariable*))outputFuncs[id];
        
        if(func != 0x0)
            func(v);
    }
}
