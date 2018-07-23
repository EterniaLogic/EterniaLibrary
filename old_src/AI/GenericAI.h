#ifndef GenericThinker_H_
#define GenericThinker_H_

// GenericThinker is just the abstract class between different versions of thinkers.

// Thinkers are basically AI that use a FSM nodal structure.


class GenericAI{
public:
    GenericAI();
    virtual ~GenericAI();

    // abstract functions
    virtual void Generate(int maxnodes) = 0; // generate this AI.
    virtual void tick(double second) = 0; // tick the nodes or pre-programmed system.
    virtual float GetEfficiency() = 0; // get the efficiency of this Thinker. (outputs number of nodes to do task for Thinker)
    virtual GenericAI* Breed(GenericAI* other) = 0; // breed attributes with another AI
    
    // used with self-evolving AIs
    virtual void SelfEvolve() = 0; // Major self-evolution function
    virtual bool BadOutput() = 0; // 
};

#endif
