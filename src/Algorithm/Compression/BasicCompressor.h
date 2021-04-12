#ifndef BASIC_COMPRESSOR_H_
#define BASIC_COMPRESSOR_H_

#include "../../Data/CharString.h"
#include "../../Data/LinkedList.hpp"


// 


typedef struct{
    int index;
    int position;
    char* match;
    char* symbol;
    
    int matchindex; // index in the list of matched code.
    char matchlen;
} occcurence;

class BasicCompressor{
private:
    bool useBlocks; // segment the data into blocks
    int blockLen; // length of each block
    CharString key;
    
    LinkedList<occcurence> occurenceTable;
public:
    // steps represents the depth that the algorith will go.
    // key is if you want the compressor to also encrypt the data.
    // Note that in decompression, this is not considered.
    BasicCompressor(int steps, CharString key);
    virtual ~BasicCompressor();
    
    // blocks do not matter for decompression. (auto-detected)
    void setBlocks(bool use, int length);
    
    CharString compress(CharString input);
    CharString decompress(CharString input);
    
    CharString loadFile(CharString location); // load a file and convert
    void saveFile(CharString location, CharString data); // convert and save a file
};

#endif
