//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PCPUSERVER_H_
#define P2PCPUSERVER_H_

#include "P2PNode.h"
#include "P2PPacket.h"

class P2PCPUServer {
    public:
        static P2PCPUServer current;
        P2PCPUServer();
        virtual ~P2PCPUServer();

        void handleCPUServerPacket(P2PNode server, P2PPacket packet);
        void sendCPUServerPacket(P2PNode server, P2PPacket packet);

        void process(); // compress data stores
};

#endif /*P2PCPUSERVER_H_*/
