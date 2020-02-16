AI in this case is also called Machine Learning. An LSTM will go through several iterations of training with test data in order to replicate the results.

***completion/testing***
Most of the machines for AI are non-working due to some Math Matrix errors computing 0s for the output.


**AI Types**
* [Convolutional Neural Network](cnn.md) (CNN, not tested)
* [Long short-term memory](lstm.md) (LSTM, no output)

*Usage*
    #include "AI/AI.h"
    
    int main(){
        
        LSTM ai; // initialize LSTM ai
        
        // Add 4 'columns' of varying sizes
        ai.addLayer(4);
        ai.addLayer(9);
        ai.addLayer(1);
        
        // Randomize the values in each node
        ai.randomize(0,1);
        
        return 1;
    }
