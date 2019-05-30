#ifndef LINKEDMAP_H_
#define LINKEDMAP_H_

#include "CharString.h"
#include "LinkedList.hpp"

// basic linked list, which includes a key to find data
//  Less bloated than the HashMap, but at the cost of CPU time when retrieving information.

// unoptimized, O(N) for get(i)/get("")
//  adding an item is only O(k)

template<class keyT, class dataT>
class LinkedMapNode {
public:
    LinkedMapNode();
    virtual ~LinkedMapNode();
    
    LinkedMapNode<keyT, dataT> *prev, *next;
    keyT key;
    dataT data;
    
    
    LinkedMapNode<keyT, dataT>* const self();
};


template<class keyT, class dataT>
class LinkedMap {
        LinkedMapNode<keyT, dataT> * baseNode;
        LinkedMapNode<keyT, dataT> * currentNode;
    public:
        LinkedMap();
        virtual ~LinkedMap();
        
        void add(keyT key, dataT data);
        dataT get(int index);
        dataT get(keyT key);
        
        
        LinkedList<keyT> getKeys();
        LinkedList<dataT> getData();
        
        void clear();
};

#endif /*LINKEDMAP_H_*/
