//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef PACKET_H_
#define PACKET_H_

#include "../../Algorithm/Cryptography/Aes256.h"

class Packet {
    public:
        char* RAW;
        long id;
};

#endif
