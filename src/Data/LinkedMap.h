#ifndef LINKEDMAP_H_
#define LINKEDMAP_H_

class LinkedMapNode {
    public:
        void * prev;
        void * next;
        void * data;
        char * key; // <-- primary key
        LinkedMapNode();
        virtual ~LinkedMapNode();
        LinkedMapNode* const self();
};


class LinkedMap {
        LinkedMapNode * baseNode;
        LinkedMapNode * currentNode;
    public:
        LinkedMap();
        virtual ~LinkedMap();
        void add(char* key, char* data);
        char* get(int index);
        char* get(char* key);
        void clear();
};

#endif /*LINKEDMAP_H_*/
