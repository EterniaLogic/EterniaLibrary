#ifndef LSTMNode_H_
#define LSTMNode_H_

#include "../../Data/LinkedList.hpp"
#include "../../Math/Functions/Sigmoid.h"

//#define debugLog(val) cout << val; cout.flush();
#define debugLog(val) //

class LSTMNode;
class LSTMNodeLink{
public:
    LSTMNodeLink(LSTMNode* n, double _weight){prevnode=n;weight=_weight;}
    LSTMNodeLink(){}
    
    LSTMNode* prevnode=0x0;
    double weight=0; // weight is also used as the input of the LSTM on the first column.
};

class LSTMNode{
public:
    double calcvalue;
    bool calculated;
    LinkedList<LSTMNodeLink*> *links; // connected links
    
    LSTMNode(){
        calcvalue=0.0;
        calculated=false;
        links = new LinkedList<LSTMNodeLink*>();
    }
    
    // used when calculating error, etc.
    LinkedList<double> getInputValues(){
        LinkedList<double> vals;
        
        LinkedListIterator<LSTMNodeLink*> it = links->getIterator();
        while(it.hasNext()){
            LSTMNodeLink* tp = it.next();
            
            if(tp->prevnode == 0x0){
                // this link is the beginning of the Graph  
                vals.add(tp->weight);          
            }else{
                vals.add(tp->prevnode->getValue());
            }
        }
        
        // use Math::sigmoid? (That only normalizes between 0 and 1!)
        
        return vals;
    }
    
    // perform weighted sum
    double getValue(){
        double newval = 0;
        debugLog("[ainode] getvalue " << this << endl);
        if(calculated) return calcvalue;
        
        debugLog("[ainode] getvalue a" << endl);
        for(int i=0;i<links->size();i++){
            LSTMNodeLink* tp = (*links)[i];
            debugLog("[ainode] getvalue b " << i << endl);
            
            if(tp->prevnode == 0x0){
                // this link is the beginning of the Graph
                newval += tp->weight;        
            }else if(tp->prevnode != this){
                newval += tp->prevnode->getValue() * tp->weight;
            }
        }
        
        // use Math::sigmoid? (That only normalizes between 0 and 1!)
        debugLog("[ainode] getvalue c" << endl);
        calculated = true;
        calcvalue = Math::sigmoid(newval);
        
        return calcvalue;
    }
    
    double getCalcValue(){
        calculated=false;
        return getValue();
    }
    
    
    void setWeight(int prevnodeid, double weight){
        debugLog("[ainode] " << this << " setWeight " << prevnodeid << " weight:" << weight << " links:" << links->size() << endl);
        if(prevnodeid > links->size()){
            cout << "link missing at " << prevnodeid << endl;
        }
        
        LSTMNodeLink* ln = (*links)[prevnodeid];
        debugLog("[ainode] setWeight link @" << ln << endl);
        ln->weight = weight;
        //(*links)[prevnodeid] = ln;
        debugLog("[ainode] setWeight done" << endl);
    }
    
    LinkedList<double> getWeights(){
        LinkedList<double> weights;
        
        for(int i=0;i < links->size();i++){
            weights.add((*links)[i]->weight);
        }
        
        return weights;
    }
    
    // performed on initialization
    void addLink(LSTMNode* prevnode, double weight){
        links->add(new LSTMNodeLink(prevnode, weight));
    }
    
    // adj
    void adjust(LinkedList<double> value){
        LinkedList<double> weights = getWeights();
        
        
        
        // do not adjust, these are inputs.
        if(weights.size() == 1){
            //debugLog(
            cout << "[ainode] adjust ignore input" << endl;
            return;
        }
        
        //debugLog("[ainode] adjust "<<value.size() << " " << weights.size() << endl);
        cout << "[ainode] adjust "<<value.size() << " " << weights.size() << " are the same? (ok if first=1)" << endl;
        
        // scalar
        if(value.size() == 1){
            double incr = value[0];
            for(int i=0;i<weights.size();i++){
                //debugLog("[ainode] adjust [1] "<<i << endl);
                cout << "[ainode] adjust [1] "<<i << " " << incr << endl;
                double nweight = weights[i] + incr;
                setWeight(i, nweight);
            }
        }else{
            for(int i=0;i<weights.size();i++){
                debugLog("[ainode] adjust x "<<i << endl);
                double nweight = weights[i] + value[i];
                setWeight(i, nweight);
            }
        }
        debugLog("[ainode] adjust done");
    }
};

#endif
