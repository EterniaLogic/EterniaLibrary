#include "testAI.h"


void testAI_XOR4(){
    AIGraph ai;
    cout << "ai" << endl;
    ai.addLayer(4);
    ai.addLayer(9);
    ai.addLayer(1);
    
    for(int k=0;k<1;k++){
        for(int i=0;i<16;i++){
            LinkedList<double> inputs = {(i&1), (i&2)>>1, (i&4)>>2, (i&8)>>3};
            LinkedList<double> outputs = {(i&1) ^ ((i&2)>>1) ^ ((i&4)>>2) ^ ((i&8)>>3)};
            cout << "train " << i << endl;
            ai.train(inputs, outputs, 1);
            cout << "end train " << i << endl;
        }
    }
    
    cout << "training done\n" << endl;
    
    for(int i=0;i<16;i++){
        LinkedList<double> inputs = {(i&1), (i&2)>>1, (i&4)>>2, (i&8)>>3};
        LinkedList<double> testin = ai.get(inputs);
        cout << "test " << (i&1)<<((i&2)>>1)<<((i&4)>>2)<<((i&8)>>3) << " = " << testin[0] << endl;
    }
}
