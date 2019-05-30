#ifndef XML_H_
#define XML_H_

#include "../CharString.h"
#include "../LinkedList.hpp"
#include "../LinkedMap.h"
#include <stdlib.h>
#include <fstream>
#include "../../Parsing/SimpleParser.h"

// XML File Format
// #comment, #text are not listed directly as subnodes
// Most of the inner processing is handled by nested LinkedLists

class XMLNode{
public:
    CharString comment; // single-line comment
    CharString text; // raw text value
    
    
    CharString tag; // xml tag
    LinkedMap<CharString,CharString> attributes;
    
    LinkedList<XMLNode*> children;
    XMLNode* parent;
    
    XMLNode(){
        parent = 0x0;
    }
};

// Just a container of XMLNodes
class XMLRoot{
public:
    XMLRoot(){}
    
    LinkedList<XMLNode*> children;
    
    static XMLRoot loadFromFile(CharString filex);
    void toFile(CharString filex);
};


#endif
