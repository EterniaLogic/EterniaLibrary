#include "../Data/AIGraph.h"

LinkedList<double> getadjustment(LinkedList<double> input, LinkedList<double> adjerror){
    LinkedList<double> adj;
    
    
    return adj;
}

void AIGraph::train(LinkedList<double> input, LinkedList<double> expectedresults, double weightstrength){
    // use Math::sigmoid(double); and Math::sigmoid_derivative(double);
    // for the difference between sameness
    debugLog("train a" << endl);
    setValues(input);
    
    // calculate error and adjustment for every column
    // starting with the lastcol, the expectedoutput - out error is used to adjust the
    //  weights. That adjustment is applied again backwards until the beginning column of the 
    //  graph is reached.
    
    
    // propogate backwards, then forwards
    // lastlayer.determineerror(expected - lastlayer.output)
    // ...
    // layer1.determineerror(layer2.delta.dot(layer2.weights.T))
    // layer1.adjust(traininginputs)
    // ...
    // lastlayer.adjust(prevlayer.output)
    
    debugLog("train b" << endl);
    
    // determine the adjustment values
    LinkedList<double> delta = expectedresults - last->getOutputs();
    debugLog("train b0" << endl);
    last->determineAdjustment(delta);
    debugLog("train b1" << endl);
    // ...
    AIGraphLayer *prev = last;
    for(int i=layers.size()-2;i>=0;i--){
        debugLog("train b2 " << i << " " << prev << endl);
        layers[i]->determineAdjustment(prev);
        prev = layers[i];
        debugLog("train b3" << endl);
    }
    
    debugLog("train c" << endl);
    
    // do adjustments
    first->adjust(input);
    prev = first;
    for(int i=1;i<layers.size();i++){
        // determine dot product
        // LinkedList<double> adjw = getAdjustedWeights();
        layers[i]->adjust(prev->getOutputs());
        prev = layers[i];
    }
    
    printLayers();
    
    
}
