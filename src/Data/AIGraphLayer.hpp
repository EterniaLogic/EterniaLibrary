#ifndef AIGRAPHLAYER_H
#define AIGRAPHLAYER_H

#include <limits>
#include "AIGraphNode.hpp"
#include "../Math/Math.h"

//#define debugLog(val) cout << val
#define debugLog(val) //
#define Logx(val) cout << val


class AIGraphLayer{
private:
    Math::Random r;
public:
    LinkedList<AIGraphNode*> nodes;
    
    LinkedList<double> error, adjustment;
    
    AIGraphLayer(double size){
        for(int i=0;i<size;i++)
            nodes.add(new AIGraphNode());
    }
    
    LinkedList<double> getOutputs(){
        LinkedList<double> outs;
        
        for(int i=0;i<nodes.size();i++){
            debugLog("[ailayer] getoutputs " << i << endl);
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
    
    void setWeights(LinkedList<LinkedList<double>> weights){
        for(int i=0;i<nodes.size();i++){
            AIGraphNode* node = nodes[i];
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
    
    void setupLinks(AIGraphLayer* prevlayer){
        if(prevlayer == 0x0){
            Logx("firstlayer set inputlinks: ");
            for(int i=0;i<nodes.size();i++){
                AIGraphNode* node = nodes[i];
                Logx("+");
                node->addLink(0x0, 0); // weight acts like an input for the entire AIGraph
            }
            Logx("\n");
        }else{ // layers after first layer
            Logx("layer setuplinks: ");
            
            
            // TODO: not setting the links correctly.
            // only setting 1, then moving away.
            for(int i=0;i<nodes.size();i++){
                AIGraphNode* node = nodes[i];
                Logx(i);
                // setup linkages between layers
                for(int j=0;j<prevlayer->nodes.size();j++){
                    AIGraphNode* pnode = nodes[i];
                    Logx("+");
                    node->addLink(pnode, r.nextDouble(std::numeric_limits<double>::min(),std::numeric_limits<double>::max()));
                }
            }
            Logx("\n");
        }
    }
    
    
    void unsetCalculated(){
        for(int i=0;i<nodes.size();i++){
            AIGraphNode* node = nodes[i];
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
        error = errordelta;
        adjustment = error*Math::sigmoid_derivative(getOutputs());
    }
    
    void determineAdjustment(AIGraphLayer* prevlayer){
        debugLog("[ailayer] determineadj" << endl);
        LinkedList<LinkedList<double>> weights = prevlayer->getWeights();
        LinkedList<double> weighteddelta;
        //prev->adjustment.dot(prev.getWeights()
        
        debugLog("[ailayer] determineadj b" << endl);
        for(int i=0;i<weights.size();i++){
            weighteddelta.add(weights[i].dot(prevlayer->adjustment));
        }
        
        debugLog("[ailayer] determineadj c" << endl);
        error = weighteddelta;
        adjustment = error*Math::sigmoid_derivative(getOutputs());
        debugLog("[ailayer] determineadj d" << endl);
    }
    
    void adjust(LinkedList<double> expectedinputs){
        // assuming that each node has a single weight instead of many
        // weights += expectedinputs dot adj;
        double weightadj = expectedinputs.dot(adjustment);
        
        // However, in this implementation, each node has multiple weights for each prev node
        for(int i=0;i<nodes.size();i++)
            nodes[i]->adjust(weightadj); // 1 into many?
    }
};

#endif
