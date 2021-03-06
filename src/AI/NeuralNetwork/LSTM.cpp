#include "LSTM.h"




// adds a layer to this graph
void LSTM::addLayer(int layersize){
    LSTMLayer *layer = new LSTMLayer(layersize);
    
    if(first == 0x0)
        first = layer;
    
    layer->setupLinks(last);
    
    last = layer;
    layers.add(layer); 
}


// initial values MUST be the size of the first few nodes
void LSTM::setValues(LinkedList<double> values){
    if(first != 0x0){
        //cout << "first setweights " << values.size() << endl;
        for(int i=0;i<first->nodes.size();i++){
            LSTMNode* node = first->nodes[i];
            //cout << "first set " <<i<< " " << node << "   value " << values[i] << endl;
            node->setWeight(0,values[i]);
        }
        
        for(int i=0;i<layers.size();i++){
            LSTMLayer* layer = layers[i];
            layer->unsetCalculated(); // reset pre-calculated values
        }
    }
}

LinkedList<double> LSTM::getValues(){
    return last->getOutputs();
}

LinkedList<double> LSTM::get(LinkedList<double> inputs){
    setValues(inputs);
    return getValues();
}


// best to randomize with a bit of leeway above and below your maximum values
void LSTM::randomize(double min, double max){
    LSTMLayer *layer;
    // r.nextDouble(std::numeric_limits<double>::min(),std::numeric_limits<double>::max())
    
    for(int i=0;i<layers.size();i++){
        layer = layers[i];
        if(layer == 0x0) continue;
        for(int j=0; j<layer->nodes.size();j++){
            LSTMNode* node = layer->nodes[j];
            for(int k=0;k<node->links->size();k++){
                node->setWeight(k, r.nextDouble(min, max));
            }
        }
    }
    
    for(int i=0;i<layers.size();i++){
        LSTMLayer* layer = layers[i];
        layer->unsetCalculated(); // reset pre-calculated values
    }
}

void LSTM::printLayers(){
    /*for(int k=0;k<layers.size();k++){
        cout << "l";
        LinkedList<LinkedList<double>> w = layers[k]->getWeights();
        cout << "ayer_widths ";
        for(int i=0;i<w.size();i++){
            LinkedList<double> w2 = w[i];
            cout << "[" << w2.size() << "]";
        }
        cout << endl;
    }*/
    
    for(int k=0;k<layers.size();k++){
        cout << "l";
        LinkedList<LinkedList<double>> w = layers[k]->getWeights();
        cout << "ayer ";
        for(int i=0;i<w.size();i++){
            LinkedList<double> w2 = w[i];
            cout << "       [";
            cout.flush();
            for(int j=0;j<w2.size();j++){
                cout << " ["; cout.flush();
                double w3 = w2[j];
                
                cout << w3; cout.flush();
                cout << "]"; cout.flush();
            }
            cout << " ]\n";cout.flush();
        }
        cout << endl;
    }
}
