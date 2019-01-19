#ifndef AIGRAPH_H
#define AIGRAPH_H

/* AIs use a graph-like structure that has weighted sums between each point.

*/
#include <limits>
#include "AIGraphNode.hpp"
#include "AIGraphLayer.hpp"
#include "../Math/Math.h"



// TODO: make it work, matricies are flipped when they shouldn't be.
//       output values are always the same. (same comment in testAI_XOR4.cpp)




#define debugLog(val) cout << val; cout.flush();
//#define debugLog(val) //

class AIGraph{
private:
    LinkedList<AIGraphLayer*> layers; // list of columns of nodes
    AIGraphLayer *first, *last;
    Math::Random r;
public:
    AIGraph(){first=0x0;last=0x0;}
    
    // adds a column to this graph, cannot remove due to how it is structured.
    void addLayer(int layersize);
    
    void setValues(LinkedList<double>); // initial values MUST be the size of the first few nodes
    LinkedList<double> getValues();
    
    LinkedList<double> get(LinkedList<double> inputs); // full-get
    
    
    // train this AI Graph using known inputs and outputs
    // Strenth between 0.000....1 and DOUBLE_MAX
    // Best to do a strength that divides by two 
    //  every training or curves off of invsigmoid.
    void train(LinkedList<double> input, 
                LinkedList<double> expectedresults, 
                double strength);
    
    
    // best to randomize with a bit of leeway 
    //  above and below your maximum values on your input/outputs
    void randomize(double min, double max); // same as resetting the training weights
    
    void printLayers();
};


#endif

