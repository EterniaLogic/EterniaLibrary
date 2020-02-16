#include "testAI.h"


void testLSTM_XOR4(){
    LSTM ai;
    cout << "ai" << endl;
    ai.addLayer(4);
    ai.addLayer(9);
    ai.addLayer(1);
    ai.randomize(0,1);
    
    // TODO: make it work, matricies are flipped when they shouldn't be.
    //       output values are always the same. (Same comment in AI_LSTM.h)
    
    for(int k=0;k<100;k++){
        //for(int i=0;i<16;i++){
        for(int i=0;i<15;i++){
            LinkedList<double> inputs = {(i&1), (i&2)>>1, (i&4)>>2, (i&8)>>3}; // @suppress("Invalid arguments")
            LinkedList<double> outputs = {(i&1) ^ ((i&2)>>1) ^ ((i&4)>>2) ^ ((i&8)>>3)}; // @suppress("Invalid arguments")
            cout << "test train " << i << " " << k << endl;
            ai.train(inputs, outputs, 1);
            cout << "end test train " << i << " " << k << endl;
        }
    }
    
    cout << "test training done\n" << endl;
    
    for(int i=0;i<16;i++){
        LinkedList<double> inputs = {(i&1), (i&2)>>1, (i&4)>>2, (i&8)>>3};  // @suppress("Invalid arguments")
        LinkedList<double> testin = ai.get(inputs);
        cout << "test " << (i&1)<<((i&2)>>1)<<((i&4)>>2)<<((i&8)>>3) << " = " << testin[0] << endl;
    }
}
