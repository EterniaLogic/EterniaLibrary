#ifndef BINARYPACKER_H_
#define BINARYPACKER_H_

#include "../Data/CharString.h"

#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

class BinaryPacker{
private:
    CharString _data;
    std::ofstream _stream;
    bool file;
    int index; // current indexer location

public:
    BinaryPacker(CharString data);
    BinaryPacker(char* data, int len);
    BinaryPacker(std::ofstream &stream); // output file stream
    
    
    // Next data types
    bool atEnd(); // checks if end of the data stream/string
    
    char nextChar(); // 8 bits (1 hex 0x00 - 0xFF)
    unsigned char nextByte(); // 8 bits 
    bool nextBool(); // 1 bits (1 hex 0x00 - 0x01)
    
    int nextInt(); // 32 bits (4 hex 0x00000000)
    unsigned int nextUInt();
    
    long nextLong();
    unsigned long nextULong();
    
    // length has to be given because strings normally terminate with NULL (\00)
    char* nextCharArray(int length);
    CharString nextCharString(int length);
    std::string nextString(int length);
};


#endif
