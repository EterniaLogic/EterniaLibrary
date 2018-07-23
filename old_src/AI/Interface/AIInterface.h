#ifndef AIINTERFACE_H_
#define AIINTERFACE_H_

#include "../../Data/LinkedList.hpp"
#include "../GenericVariable.h"

// interface for AIs, acts as stimuli and output.

class AIInterface{
private:
    LinkedList<unsigned int> outputFuncs;
    LinkedList<GenericVariable> inputs;
public:
    AIInterface();
    
    void addInput(GenericVariable* value);
    void setInput(int id, GenericVariable* value);
    GenericVariable* getInput(int id);
    
    
    // standard Finite State Machine AI outputer
    void addOutputFunction(void (*func)(GenericVariable*));
    void useOutput(int id, GenericVariable* v);
    
    
    // used with Advanced Thinker, multi-parameter output function
    //void _addOutputFunction(void* func);
    //void _useOutput(std::initializer_list<GenericVariable> values); // (GenericVariable&&... values)
};


#endif
