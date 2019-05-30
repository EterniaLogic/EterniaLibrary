#include "LinkedMap.h"
#include "iostream"

template<class keyT, class dataT>
LinkedMapNode<keyT, dataT>::LinkedMapNode() {
    //key = "";
    //data = 0x0;
    prev = next = 0x0;
}

template<class keyT, class dataT>
LinkedMapNode<keyT, dataT>::~LinkedMapNode() {
    //key = "";
    //data = 0x0;
    prev = next = 0x0;
}

template<class keyT, class dataT>
LinkedMapNode<keyT, dataT>* const LinkedMapNode<keyT, dataT>::self() {
    return this;
}




template<class keyT, class dataT>
LinkedMap<keyT, dataT>::LinkedMap() {
    baseNode = currentNode = 0x0;
}

template<class keyT, class dataT>
LinkedMap<keyT, dataT>::~LinkedMap() {}

template<class keyT, class dataT>
void LinkedMap<keyT, dataT>::add(keyT key,dataT cc) {
    //adds a Void* Object. This can be declared when using the list.
    if(baseNode == 0x0){
        baseNode = currentNode = new LinkedMapNode<keyT, dataT>();
    }else{
        LinkedMapNode<keyT, dataT> nnode = new LinkedMapNode<keyT, dataT>();
        currentNode->next = nnode;
        currentNode = nnode;
    }
    
    currentNode->key = key;
    currentNode->data = cc;
}

template<class keyT, class dataT>
dataT LinkedMap<keyT, dataT>::get(int index) {
    LinkedMapNode<keyT, dataT> *current = baseNode;
    for(int i=0; i<index; i++) {
        current = baseNode->next;
    }
    return current->data;
}

template<class keyT, class dataT>
dataT LinkedMap<keyT, dataT>::get(keyT key) {
    LinkedMapNode<keyT, dataT> *current = baseNode;
    while(current != 0x0) {
        if(baseNode->key == key) {
            return current->data;
        }
        current = baseNode->next;
    }
    
    return 0; // ???
}


template<class keyT, class dataT> 
LinkedList<keyT> LinkedMap<keyT, dataT>::getKeys(){
    LinkedList<keyT> listx;
    
    LinkedMapNode<keyT, dataT> *current = baseNode;
    while(current != 0x0) {
        listx.add(current->data);
        current = baseNode->next;
    }
    
    return listx;
}

template<class keyT, class dataT> 
LinkedList<dataT> LinkedMap<keyT, dataT>::getData(){
    LinkedList<dataT> listx;
    
    LinkedMapNode<keyT, dataT> *current = baseNode;
    while(current != 0x0) {
        listx.add(current->key);
        current = baseNode->next;
    }
    
    return listx;
}


template<class keyT, class dataT>
void LinkedMap<keyT, dataT>::clear() {
    if(baseNode != 0x0){
        delete baseNode->self();
        baseNode = new LinkedMapNode<keyT, dataT>();
    }
}
