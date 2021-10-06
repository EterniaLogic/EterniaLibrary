#ifndef BINARYUNPACKER_H_
#define BINARYUNPACKER_H_

#include "../Data/CharString.h"

#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

class BinaryUnpacker{
private:
    CharString _data;
    std::ifstream stream;
    bool file;
public:
    BinaryUnpacker();
    BinaryUnpacker(int length); // much more efficient if ending length is known
    BinaryUnpacker(std::ifstream &stream); // input file stream
    
    // Return
    CharString getBinaryData();
    
    
    // PUT data
    void put(char c);
    void put(unsigned char c);
    void put(bool b);
    void put(int i);
    void put(unsigned int i);
    void put(long l);
    void put(unsigned long l);
    void put(float f);
    void put(double d);
    void put(char* c, int length);
    void put(CharString s);
    void put(std::string s);
};


#endif
