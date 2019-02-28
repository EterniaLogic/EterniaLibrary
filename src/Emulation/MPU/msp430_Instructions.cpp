


#include "msp430.h"

// Manage instructions for the msp430
// these instructions modify the local memory space only

namespace MSP430{
    void MSP430::rrc(unsigned int addr) {}
    void MSP430::swpb(unsigned int addr) {}
    void MSP430::mov(unsigned int addr, unsigned int value) {}
    void MSP430::rra(unsigned int addr) {}
    void MSP430::sxt(unsigned int addr) {}
    void MSP430::push(unsigned int addr) {} // move operator to stack and SP+2
    void MSP430::call(unsigned int addr) {} // push twice and change PC
    void MSP430::reti() {} // gets location from stack reg

    // jnz (Z flag on sr)
    void MSP430::jne(unsigned int location) {
        if(!(_mem(SR) & _Z)) {
            // Z flag is not set
            PC = location; // jump to location
        }
    }

    // jz
    void MSP430::jeq(unsigned int location) {
        if(_mem(SR) & _Z) {
            // Z flag is set
            PC = location; // jump to location
        }
    }

    void MSP430::jnc(unsigned int location) {
        if(!(_mem(SR) & _C)) {
            // C flag is not set
            PC = location; // jump to location
        }
    }

    void MSP430::jc(unsigned int location) {
        if(_mem(SR) & _C) {
            // C flag is set
            PC = location; // jump to location
        }
    }

    void MSP430::jn(unsigned int location) {
        if(_mem(SR) & _N) {
            // C flag is set
            PC = location; // jump to location
        }
    }

    void MSP430::jge(unsigned int location) {
        bool N_ = (_mem(SR) & _N);
        bool V_ = (_mem(SR) & _V);
        if(N_ == _V) {
            // C flag is set
            PC = location; // jump to location
        }
    }

    void MSP430::jl(unsigned int location) {
        bool N_ = (_mem(SR) & _N);
        bool V_ = (_mem(SR) & _V);
        if(N_ != _V) {
            // C flag is set
            PC = location; // jump to location
        }
    }

    void MSP430::jmp(unsigned int location) {
        PC = location;
    }
}
