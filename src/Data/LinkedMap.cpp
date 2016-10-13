#include "LinkedMap.h"
#include "iostream"

LinkedMapNode::LinkedMapNode() {
    key = "";
    data = 0x0;
}
LinkedMapNode::~LinkedMapNode() {
    key=0x0;
    data = 0x0;
    delete next;
}
LinkedMapNode* const LinkedMapNode::self() {
    return this;
}

LinkedMap::LinkedMap() {
    baseNode = new LinkedMapNode();
    currentNode = baseNode;
}

LinkedMap::~LinkedMap() {
}

void LinkedMap::add(char* key,char* cc) {
    //adds a Void* Object. This can be declared when using the list.
    currentNode->next = new LinkedMapNode();
    LinkedMapNode * gg = ((LinkedMapNode*)currentNode);
    ((LinkedMapNode*)currentNode)->key = key;
    ((LinkedMapNode*)currentNode)->data = cc;
    currentNode = ((LinkedMapNode*)gg->next);
}

char* LinkedMap::get(int index) {
    LinkedMapNode * current = baseNode;
    for(int i=0; i<index; i++) {
        current = (LinkedMapNode*)baseNode->next;
    }
    return (char*)current->data;
}

char* LinkedMap::get(char* key) {
    LinkedMapNode * current = baseNode;
    while(&current != 0x0) {
        if((char*)(LinkedMapNode*)baseNode->key == key) {
            return (char*)current->data;
        }
        current = (LinkedMapNode*)baseNode->next;
    }
    //return (char*)current->data;
    return "";
}

void LinkedMap::clear() {
    delete baseNode->self();
    baseNode = new LinkedMapNode();
}
