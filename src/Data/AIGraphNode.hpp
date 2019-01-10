#ifndef AIGraphNode_H_
#define AIGraphNode_H_

#include "LinkedList.hpp"

//#define debugLog(val) cout << val
#define debugLog(val) //

class AIGraphNode;
class AIGraphNodeLink{
public:
    AIGraphNodeLink(AIGraphNode* n, double _weight){prevnode=n;weight=_weight;}
    AIGraphNodeLink(){}
    
    AIGraphNode* prevnode=0x0;
    double weight=0; // weight is also used as the input of the AIGraph on the first column.
};

class AIGraphNode{
public:
    double calcvalue;
    bool calculated;
    LinkedList<AIGraphNodeLink> *links; // connected links
    
    AIGraphNode(){
        calcvalue=0.0;
        calculated=false;
        links = new LinkedList<AIGraphNodeLink>();
    }
    
    // used when calculating error, etc.
    LinkedList<double> getInputValues(){
        LinkedList<double> vals;
        
        LinkedListIterator<AIGraphNodeLink> it = links->getIterator();
        while(it.hasNext()){
            AIGraphNodeLink tp = it.next();
            
            if(tp.prevnode == 0x0){
                // this link is the beginning of the Graph  
                vals.add(tp.weight);          
            }else{
                vals.add(tp.prevnode->getValue());
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
            AIGraphNodeLink tp = (*links)[i];
            debugLog("[ainode] getvalue b " << i << endl);
            
            if(tp.prevnode == 0x0){
                // this link is the beginning of the Graph
                newval += tp.weight;        
            }else if(tp.prevnode != this){
                newval += tp.prevnode->getValue() * tp.weight;
            }
        }
        
        // use Math::sigmoid? (That only normalizes between 0 and 1!)
        debugLog("[ainode] getvalue c" << endl);
        calculated = true;
        calcvalue = newval;
        
        return newval;
    }
    
    double getCalcValue(){
        calculated=false;
        return getValue();
    }
    
    
    void setWeight(int prevnodeid, double weight){
        debugLog("[ainode] " << this << " setWeight " << prevnodeid << " weight:" << weight << " links:" << links.size() << endl);
        if(prevnodeid > links->size()){
            cout << "link missing at " << prevnodeid << endl;
        }
        
        AIGraphNodeLink ln = (*links)[prevnodeid];
        ln.weight = weight;
        (*links)[prevnodeid] = ln;
    }
    
    LinkedList<double> getWeights(){
        LinkedList<double> weights;
        
        for(int i=0;i < links->size();i++){
            weights.add((*links)[i].weight);
        }
        
        return weights;
    }
    
    // performed on initialization
    void addLink(AIGraphNode* prevnode, double weight){
        links->add(AIGraphNodeLink(prevnode, weight));
    }
    
    // turn 1 adjust value into many adjustments of all of the weights
    void adjust(double value){
        // Test each weight and see which one has the closest change needed.
        // split value into many parts based on weight differences
        
        // simple for now:
        LinkedList<double> weights =  getWeights();
        for(int i=0;i<weights.size();i++){
            double nweight = weights[i] + value;
            setWeight(i, nweight);
        }
    }
};

#endif
