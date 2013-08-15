#ifndef SECURED_GPU_DATA_H_
#define SECURED_GPU_DATA_H_

#include "../../../Data/LinkedList.hpp"
#include "../../../MiscLib/CharString.h"
#include "GPUInstruction.h"

// This is a packet that is encrypted.
// Header: 68 78 95 72
// Contents: List of instructions to be performed on GPU

// Structure of decrypted form:
//      - Number of instructions
//      - Instructions separator
//      - Instructions ender
//      - pure stream

class SecuredGPUData
{
public:
  SecuredGPUData(char* packet); // pure decrypted packet data taken in
private:
  int instructionNumber;
  char separator;
  char ender;
  
  LinkedList<CharString>* instructions;
};

#endif 
 
