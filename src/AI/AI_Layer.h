#ifndef AILAYER_H_
#define AILAYER_H_

#include "../Data/LinkedList.hpp"
#include "../Math/Math.h"

class AILayer {

public:
    AILayer();
    LinkedList<double> synapse_weights;
    
    // Layers for forward and backward propagation
    AILayer *prev,*next;
    
    // use reverse sigmoid with the dot product of inputs and synapse weights
    // forwards think() to the next AI Layer.
    //  returns the output from either the forward layer or this think values
    LinkedList<double> think(LinkedList<double> inputs);
    
    
    // Backward propagation
    // error = training_set_outputs - output
    // weights += dot(training_set_inputs.T, error * sigmoid_derivative(output))
    void errorcorrect(LinkedList<double> expected);
};

#endif
