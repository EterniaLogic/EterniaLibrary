//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECURED_GPU_Header_H_
#define SECURED_GPU_Header_H_

#include "../../Packet.hpp"

// This is a packet that is encrypted.
// Contents: List of instructions for incoming encrypted data

// Structure of decrypted form:
//      - Number of Secured Process Instructable packets
//      - Number of data packets

class SecuredGPUHeader : private Packet {
    public:
        SecuredGPUHeader(char* in) {
            id = 1024512;
        }

    private:
        int instructablePackets;
        int dataPackets;
};

#endif
