#ifndef AIML_H
#define AIML_H

// Interface for Machine Learning
#include "../../Data/LinkedList.hpp"

// Artificial Neural Networks
// https://en.wikipedia.org/wiki/Artificial_neural_network
// CNN, LSTM, RNN
// CNN is for images
// RNN is for time-specific data
// LSTM is for raw data (0 or 1)


// Deep Learning uses sub-units of LSTMs, CNNs and RNNs in a massive map

class NeuralNetwork{
public:
    void setValues(LinkedList<double>); // initial values MUST be the size of the first few nodes
    LinkedList<double> getValues();
    LinkedList<double> get(LinkedList<double> inputs); // full-get with a first-level input
    
    void train(LinkedList<double> input, LinkedList<double> expectedresults, double weightstrength);
};

#endif
