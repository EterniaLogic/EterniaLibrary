#ifndef LSTMLAYER_H
#define LSTMLAYER_H

#include <limits>
#include "LSTMNode.hpp"
#include "../../Math/Math.h"

#define debugLog(val) cout << val; cout.flush();
//#define debugLog(val) //
#define Logx(val) cout << val


class LSTMLayer{
private:
    Math::Random r;
public:
    LinkedList<LSTMNode*> nodes;
    
    Math::Matrix* adjusted;
    
    LSTMLayer(double size){
    	adjusted = 0x0;
        for(int i=0;i<size;i++)
            nodes.add(new LSTMNode());
    }
    
    LinkedList<double> getOutputs(){
        LinkedList<double> outs;
        
        for(int i=0;i<nodes.size();i++){
            //debugLog("[ailayer] getoutputs " << i << endl);
            outs.add(nodes.get(i)->getValue());
        }
        
        return outs;
    }
    
    LinkedList<LinkedList<double>> getWeights(){
        LinkedList<LinkedList<double>> outs;
        
        for(int i=0;i<nodes.size();i++){
            outs.add(nodes[i]->getWeights());
        }
        
        return outs;
    }
    
    /*LinkedList<LinkedList<double>> getWeightsTransposed(){
        LinkedList<LinkedList<double>> weights = getWeights();
        LinkedList<LinkedList<double>> out;
        
        for(int i=0;i<weights.size();i++){
            LinkedList<double> weights1 = weights[i];
            for(int j=0;j<weights1.size();j++){
                double weights2 = weights1[j];
                
                if(j > out.size()-1) out.add(LinkedList<double>());
                out[j].add(weights2);
            }
        }
        
        
        return out;
    }*/
    
    void setWeights(LinkedList<LinkedList<double>> weights){
        for(int i=0;i<nodes.size();i++){
            LSTMNode* node = nodes[i];
            LinkedList<double> weightl = weights[i];
            debugLog("node sw " << node << endl);
            
            if(i > weights.size()-1){
                debugLog("node sw after??" << endl);
                node->setWeight(i, 0);
                
            }else{
                debugLog("node sw i" << i << endl);
                for(int j=0;j<node->links->size();j++){
                    node->setWeight(j, weights[i][j]);
                }
            }
            debugLog("done node sw " << node << endl);
        }
        
        unsetCalculated();
    }
    
    void setupLinks(LSTMLayer* prevlayer){
        // clear out the links in case resetting links
        for(int i=0;i<nodes.size();i++){
            LSTMNode* node = nodes[i];
            node->links->clear(); // weight acts like an input for the entire LSTM
        }
    
        if(prevlayer == 0x0){
            Logx("firstlayer set inputlinks: ");
            for(int i=0;i<nodes.size();i++){
                LSTMNode* node = nodes[i];
                Logx("+");
                node->addLink(0x0, 0); // weight acts like an input for the entire LSTM
            }
            Logx("\n");
        }else{ // layers after first layer
            Logx("layer setuplinks: ");
            
            for(int i=0;i<nodes.size();i++){
                LSTMNode* node = nodes[i];
                Logx(i);
                // setup linkages between layers
                for(int j=0;j<prevlayer->nodes.size();j++){
                    LSTMNode* pnode = nodes[i];
                    Logx("+");

                    node->addLink(pnode, r.nextDouble());
                }
            }
            Logx("\n");
        }
        
        unsetCalculated();
    }
    
    
    void unsetCalculated(){
        for(int i=0;i<nodes.size();i++){
            LSTMNode* node = nodes[i];
            node->calculated=false;
        }
    }
    
    
    // layerlast.determineerror(expected - lastlayer.output)
    // ...
    // layer1.determineerror(layer2.delta.dot(layer2.weights.T))
    // layer1.adjust(traininginputs)
    // ...
    // lastlayer.adjust(prevlayer.output)
    void determineAdjustment(LinkedList<double> errordelta){
        debugLog("[ailayer] first determineadj" << endl);
        
        cout << "FIRST ADJP List delta" << endl;
        errordelta.printlist();
        getOutputs().printlist();
        Math::sigmoid_derivative(getOutputs()).printlist();
        LinkedList<double> adjp = errordelta*Math::sigmoid_derivative(getOutputs());
        
        cout << "FIRST ADJP List (delta*sigmoid(output)), size=" << adjp.size() << endl;
        adjp.printlist();
        
        LinkedList<LinkedList<double>> adjl;
        adjl.add(adjp);
        adjusted = LinkedList<double>::toMatrix(adjl);
        adjusted->transpose();
        
        cout << "FIRST adjusted:::::::::::::::::::::::: " << endl;
        adjusted->toOutput();
    }
    
    void determineAdjustmentL(LSTMLayer* prevlayer){
        debugLog("[ailayer] determineadj" << endl);
        //layer1.determineError(layer2.delta.dot(layer2.synaptic_weights.T))
        
        Math::Matrix* prevweights = 
            LinkedList<double>::toMatrix(prevlayer->getWeights());
        prevweights->transpose();
        
        debugLog("[ailayer] determineadj b" << endl);
        cout << "a" << endl;
        Math::Matrix* weighteddelta = 
            prevlayer->adjusted->dot(prevweights);
        cout << "b" << endl;
        
        debugLog("[ailayer] determineadj c" << endl);
        //error = weighteddelta;
        //adjustment = error*Math::sigmoid_derivative(getOutputs());
        
        /*adjustment.clear();
        for(int i=0;i<weighteddelta.size();i++){
            LinkedList<double> wd = weighteddelta[i];
            adjustment.add(wd * Math::sigmoid_derivative(getOutputs()));
        }*/
        
        LinkedList<LinkedList<double>> adjl;
        for(int i=0;i<weighteddelta->columns;i++){
            LinkedList<double> wcol = 
                LinkedList<double>(weighteddelta->values[i], weighteddelta->rows);
            LinkedList<double> d = wcol * Math::sigmoid_derivative(getOutputs());
            adjl.add(d);
        }
        adjusted = LinkedList<double>::toMatrix(adjl);
        adjusted->transpose();
        
        cout << "adjusted:::::::::::::::::::::::: " << endl;
        adjusted->toOutput();
        
        debugLog("[ailayer] determineadj d" << endl);
    }
    
    void adjust(LinkedList<double> expectedinputs){
        // assuming that each node has a single weight instead of many
        // weights += expectedinputs dot adj;
        unsetCalculated();
        
        expectedinputs.printlist();
        
        LinkedList<LinkedList<double>> inputw;
        inputw.add(expectedinputs);
        Math::Matrix* inputm = LinkedList<double>::toMatrix(inputw);
        //inputm->transpose(); // transpose!
        cout << "adjc" << endl;
        //adjusted->transpose();
        Math::Matrix* weightadj = inputm->dot(adjusted);
        //weightadj->transpose();
        cout << "adjd" << endl;
        
        weightadj->toOutput();
        
        // However, in this implementation, each node has multiple weights for each prev node
        // use by columns
        for(int i=0;i<weightadj->rows;i++){
            debugLog("[ailayer] adjust d " << weightadj->rows << endl);
            double* col = weightadj->values[i];
            LinkedList<double> adj = LinkedList<double>(col, weightadj->rows);
            nodes[i]->adjust(adj); // 1 into many?
        }
    }
};

#endif
