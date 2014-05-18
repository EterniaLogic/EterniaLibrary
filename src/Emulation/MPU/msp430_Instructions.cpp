//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------


#include "msp430.h"

// Manage instructions for the msp430
// these instructions modify the local memory space only


void rrc(unsigned int addr);
void swpb(unsigned int addr);
void mov(unsigned int value, unsigned int addr);
void rra(unsigned int addr);
void sxt(unsigned int addr);
void push(unsigned int addr); // move operator to stack and SP+2
void call(unsigned int addr); // push twice and change PC
void reti(); // gets location from stack reg

 // jnz (Z flag on sr)
void jne(unsigned int location){
    if(!(_mem() & Z)){
        // Z flag is not set
        PC = location; // jump to location
    }
}

// jz
void jeq(unsigned int location){
    if(_mem() & Z){
        // Z flag is set
        PC = location; // jump to location
    }
}

void jnc(unsigned int location){
    if(!(_mem() & C)){
        // C flag is not set
        PC = location; // jump to location
    }
}

void jc(unsigned int location){
    if(_mem() & C){
        // C flag is set
        PC = location; // jump to location
    }
}

void jn(unsigned int location){

}

void jl(unsigned int location){
}

void jmp(unsigned int location){
    
}