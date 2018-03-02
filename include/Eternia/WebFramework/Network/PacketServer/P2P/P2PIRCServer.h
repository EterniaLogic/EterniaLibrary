//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PIRCSERVER_H_
#define P2PIRCSERVER_H_

#include "P2PInc.h"

class P2PIRCServer {
    public:
        static P2PIRCServer current;
        P2PIRCServer();
        virtual ~P2PIRCServer();

        void handlesIRCPacket(P2PNode client, P2PPacket packet); // Manages range of packet (May contact L1+ ir massive IRC)
        void sendIRCPacket(P2PNode client, P2PPacket packet);
};

#endif /*P2PIRCSERVER_H_*/
