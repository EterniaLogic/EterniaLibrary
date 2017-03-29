//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------


#ifndef MSP430_OPCODES
#define MSP430_OPCODES

//15  14  13  12  11  10  9  8  7  6  5  4  3  2  1  0
//0   0   0   1   0   0  |Op      |BW|Ad    |Dest reg| << ONE OP
//0   0   1  |Condition  |PC offset (10 bit)         | << JMP OP
//Opcode         |Source reg   |Ad|BW|As  |Dest reg  | << TWO OP

// BW = B/W = Byte(0) or Word(1)?

// one-operand instructions
enum MSP430_OP_1 {MSP430_RRC, MSP430_SWPB, MSP430_RRA, MSP430_SXT,
                  MSP430_PUSH, MSP430_CALL, MSP430_RETI
                 };
enum MSP430_OP_JMP {MSP430_JNE, MSP430_JEQ, MSP430_JNC, MSP430_JC, MSP430_JN,
                    MSP430_JGE,MSP430_JL, MSP430_JMP
                   };


// two-operand instructions
enum MSP430_OP_2 {NUL1, NUL2, NUL3, NUL4, MSP430_MOV, MSP430_ADD, MSP430_ADDC, MSP430_SUBC, MSP430_SUB, MSP430_CMP,
                  MSP430_DADD, MSP430_BIT, MSP430_BIC, MSP430_BS, MSP430_XOR, MSP430_AND
                 };

#endif
