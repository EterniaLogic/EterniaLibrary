//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECURED_GPU_DATA_H_
#define SECURED_GPU_DATA_H_

#include "../../Packet.hpp"

// This is a packet that is encrypted.
// Header: 52 75 34 17
// Contents: List or stream of data

// Structure of decrypted form:
//      - Type of data (Stream / List, ect)
//      - byte length of data
//      - Listlength (if list type)
//      - pure data

class SecuredGPUData : public Packet {
    public:
        SecuredGPUData(char* direct) {
            id=130866;
            bitlen=0;
            listlen=0;

        }

    private:
        int bitlen;
        int listlen;
};

#endif
