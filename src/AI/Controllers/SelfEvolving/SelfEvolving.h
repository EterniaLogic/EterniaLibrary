#ifndef SELF_EVOLVING_H_
#define SELF_EVOLVING_H_

#include "SelfEvolvingTask.h"
#include "../GenericAI.h"

// The Self-Evolving generator allows a single Thinker for a bunch of tasks.
//  Each thinker is self-evolving and will enumerate every possibility to get to the required task.

// The thinkers are aware of the final "Goal" that they need to get to, but they will need to explore every aspect
//  to get statistically close to the objective.

// This is all about "Artificial intelligence". Self-evolving code nodes.
// Say there is a muscle. If the AI increases the muscle too much, the incoming pain from a joint will go up exponentially.
// This AI only learns by the feedback from the environment.

class SelfEvolving{
public:
    SelfEvolving();
    virtual ~SelfEvolving();
};


#endif
