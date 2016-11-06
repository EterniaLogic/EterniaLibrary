//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECURED_CPU_INSTRUCTABLES_H_
#define SECURED_CPU_INSTRUCTABLES_H_

#include "../../../../Data/LinkedList.hpp"
#include "../../../../Data/CharString.h"
#include "../../Packet.hpp"
#include "../ProcessorInstruction.h"

// This is a packet that is encrypted.
// Header: 68 78 95 72
// Contents: List of instructions to be performed on GPU

// Structure of decrypted form:
//      - Number of instructions
//      - Instructions separator
//      - Instructions ender
//      - pure stream

class SecuredCPUInstructables : private Packet {
    public:
        SecuredCPUInstructables(char* packet) { // pure decrypted packet data taken in
            id = 1024512;
        }

    private:
        int instructionNumber;
        char separator;
        char ender;

        LinkedList<CharString>* instructions;
};

#endif

