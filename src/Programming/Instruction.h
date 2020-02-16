#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "../Data/includes.h"

// Highly Generic instruction assembler. (8-256 bit assembler)
// Also, it would seem that since each manufacturer tried to be innovative with each revision. This makes making a compiler more difficulty.

// Instruction for the CPU. OpCode values are based off of the OS Type.
// Instructions may be saved into a binary file. (Does not include binary Header, .text, .data)
// This system of compilation allows for 8-256 bit systems. Note that the compiled max bit is dependant on the OS in which it is compiled on.

// The headers for all of these are different.
// ELF - Executable and linkable format (Unix/Linux)
// PXE - Preboot Execution Environment (Windows)
// COFF - SVR3 = ...? 
// obj - oldest unix format (FreeBSD)


enum CPLBASEFMT {CPL_INTEL, CPL_AMD, CPL_NVIDIA, CPL_TI, CPLOTHER};

class Instruction{
private:
    char prefix; // some opcodes have a specific prefix
    short opcode; // Primary opcode. 16-bit max. (Highly dependent on the OS+CPU, but 2^11,  1024 seems the be the max # of opcodes on 64-bits)
    
    // in/out/...? variables for instructions. Actual compiled size is dependent on manufacturer
    int R1; // Opcodes with a req for R1 (in/out?/...)
    int R2; // Opcodes with a req for R2 (in/out?)
    int R3; // Opcodes with a req for R3 (in/out/.../?)
    int R4; // Makes no sense to have this fourth variable.
public:
    Instruction(CPLBASEFMT baseCompany);
    
    // Compilation is highly dependent on the CPU type.
    CharString compile8(); // compile this Instruction for 8-bit
    CharString compile16(); // compile this Instruction for 16-bit
    CharString compile32(); // compile this Instruction for 32-bit
    CharString compile64(); // compile this Instruction for 64-bit
    CharString compile128(); // compile this Instruction for 128-bit
    CharString compile256(); // compile this Instruction for 256-bit
};

#endif
