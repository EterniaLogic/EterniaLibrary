#ifndef AI_FACTORY_H
#define AI_FACTORY_H

// The AI Factory creates, trains, and destroys Machine Learning nodes.

// Monarch - Conscious node that controls all
// AIFactory - Median layer, follows Monarch's goals. (Nobles)
// AIMLs - Machine Learning subnodes subconscious peasant villages

#include "../Data/includes.h"
#include "NeuralNetwork/NeuralNetwork.h"
#include "NeuralNetwork/LSTM.h"

class AIFactory{
public:
    AIFactory(){}
    
    NeuralNetwork nodeman; // node create/delete/trainer
    LinkedList<NeuralNetwork> networks; // Machine Learning nodes, subconsciousnesses
};

#endif

