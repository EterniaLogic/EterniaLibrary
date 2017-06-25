#ifndef GENETIC_GRADER_H_
#define GENETIC_GRADER_H_

#include "../Data/LinkedList.hpp"
#include "GenericThinker.h"

enum TRequirements {TR_HIGHESTVAL, TR_LOWESTVAL, TR_CLOSESTVAL, TR_ISTRUE, TR_ISFALSE};
class GeneticGrader;
// The grader is specific to the application.
// Grade is from 0 to 100

// A Thinker Requirement can be any specified value. Whether it be the highest 
//  possible distance travelled compared to others, FSM that decodes/encodes speech, ect.
class ThinkerRequirement{
public:
    // external function to grade the thinkers with.
    bool (*reqTester)(GenericAI*); // TR_ISTRUE, TR_ISFALSE
    float value; // used with TR_CLOSESTVAL
    TRequirement type;
    
    
    // TR_HIGHESTVAL, TR_LOWESTVAL are global requirements for the population.
    
    ThinkerRequirement();
};

class GeneticGrader{
public:
    GeneticGrader();
    
    // List of requirements and constraints to grade the thinkers
    LinkedList<ThinkerRequirement> requirementsList;
};

#endif
