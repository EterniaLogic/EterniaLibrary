
#ifndef MSP430_h
#define MSP430_h

#include <math.h>
#include <ctime>

#include "msp430g2553.h"
#include "msp430_Opcodes.h"
#include "msp430_Registers.h"
#include "msp430_declare_consts.h"
#include "../../Data/LinkedList.hpp"
#include "../../Data/HashMap.hpp"

#define MEM_SIZE 65535
#define RAM_REGION 0x200
#define RAM_SIZE 512


// Memory manipulation preprocessor methods
#define _mem(addr) this->Memory[addr]
#define _mem_2(addr) this->Memory[addr+1]
#define _m(addr) _mem(addr)
#define _m16(addr) _mem(addr) + _mem_2(addr)<<4 // Little Endian has MSB go first
#define _setTo16Value1(addr, value) _mem(addr) = value & 0xFF00; _mem_2(addr) = value & 0xFF;
#define _setTo16Value2(addr, val, val16) _mem(addr) = val16; _mem_2(addr) = val;



enum INTERRUPT_ID {
    IID_RESET, IID_OSC_MEM_FAULT, IID_TA1_A0, IID_TA1_A1, IID_COMPARATOR_A,
    IID_WDT, IID_TA0_A0, IID_TA0_A1, IID_USCI_RECEIVE, IID_USCI_TRANSMIT,
    IID_ADC10, IID_PORT2, IID_PORT1
};

class InterruptHandle {
    public:
        InterruptHandle() {}
        INTERRUPT_ID id;
        int* method; // << method to call
};

// Emulate the MSP430 processor; This will only work with
//      compiled MSP430 projects using either assembler
//      or c++
class MSP430 {
    private:
        unsigned char Memory[MEM_SIZE]; // declare raw memeory region
        unsigned int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15;

        // timing helper variables
        int smclk_cnt;
        bool paused, T0_up, T1_up;

        // internal handle
        HashMap<LinkedList<InterruptHandle> >* interruptHandles;
        void handleInterrupt(INTERRUPT_ID id);
        void testInterrupts();
        void exec(unsigned int address); // execute a line with PC

        void runTimer0(bool is_mclk);
        void runTimer1(bool is_mclk);
        void handleUSCIA();
        void handleUSCIB();


    public:
        MSP430();
        void init(); // or reinit msp430
        void loadHEX(char* loc); // load a hex desriptor file
        void load(char* loc); // load a raw memory file (0xFFFF long)

        // master clock (managed by Status register)
        //   interrupts also handled here (IFG watch)
        void mclk();
        void smclk();



        // get a byte from the memory
        unsigned char getByte(unsigned int address); // [address]

        // get a word from the memory
        unsigned int getWord(unsigned int address); // [address]<<4 + [address+1]

        void setByte(unsigned int address, unsigned char value);
        void setWord(unsigned int address, unsigned int value);

        void setADC10Value(unsigned int value); // sets ADC10MEM and sets ADC10IFG

        // set a method to be called upon a specific INTERRUPT_ID
        void addInterruptHandle(INTERRUPT_ID id, void (func)());

        void Pause(); // pause processor
        void Continue(); // continue processor

        // Internal operations
    private:
        void rrc(unsigned int addr);
        void swpb(unsigned int addr);
        void mov(unsigned int addr, unsigned int value);
        void rra(unsigned int addr);
        void sxt(unsigned int addr);
        void push(unsigned int addr); // move operator to stack and SP+2
        void call(unsigned int addr); // push twice and change PC
        void reti(); // gets location from stack reg

        void jne(unsigned int location); // jnz
        void jeq(unsigned int location); // jz
        void jnc(unsigned int location); // jump not carry
        void jc(unsigned int location); // jump carry
        void jn(unsigned int location); // jump negative
        void jge(unsigned int location);
        void jl(unsigned int location);
        void jmp(unsigned int location);
};

#endif
