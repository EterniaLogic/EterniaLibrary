#ifndef NONODER_H_
#define NONODER_H_

#include "../../GenericAI.h"

// This type of AI is not really an AI. It can be pre-programmed to do specific things,
//  but the only things that this AI have are variables.

// No built-in intelligence, only pre-specified instructions.


// The point of this system is to allow for genetic manipulation within a population.
//  Intelligence does not grow, but variable attributes can be mixed and matched.

// The programmer MUST program the ticker.

class NoNoder : public GenericAI{
public:
    NoNoder();
    virtual ~NoNoder();

    void Generate(int maxnodes); // Generate random thought map, only used when seeding a population.
    void tick(double second);  // seconds are irrelevant here. Tick through all i/o nodes
    float GetEfficiency(); // not used here. Efficiency is only based on variables.
    GenericAI* Breed(GenericAI* other); // breed variable attributes with another AI.
    
    // functions for self-evolving AIs.
    void SelfEvolve();
};

#endif
