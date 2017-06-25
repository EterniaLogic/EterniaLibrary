#ifndef SELF_EVOLVING_TASK_H_
#define SELF_EVOLVING_TASK_H_


// The Self-Evolving Task pretty much gives the Thinker a goal to perform.
//  It provides the interface and environment for the Thinker to do something in.

// There can be a cross-coordinating Thinker that tells other Thinkers what their task is.
//  It can put them into a dormant state.


// Examples:
//  Input says "hello", output says "How are you?"
//  Input gives leg position, output changes leg
//  Input is several other Thinkers, output will make them walk over time.
//  Input is a set of images over time. Determine distance from an object and output a value.

class SelfEvolvingTask{
public:
    SelfEvolvingTask();
    virtual ~SelfEvolvingTask();
};

#endif
