//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PLCLIENT_H_
#define P2PLCLIENT_H_

#include "P2PInc.h"

enum P2PTYPE {data,cpu,L,E};
class P2PLClient {
    public:
        static P2PLClient current;
        P2PLClient();
        virtual ~P2PLClient();

        void SendGamePacket(P2PPacket packet);

        int level; // server level (or L), only changed if participating in P2P. *cough* most likely to happen.
        P2PNode* LBranch; // current L Branch that we are on. (changes over time)
        P2PTYPE type;

        //P2PLServer* LServer;

        // handles
        void handlePacket(P2PNode server, P2PPacket packet); // sorts packet
        void handleGamePacket(P2PNode server, P2PPacket packet); // Game packet pertains to operations within the game
        void handleNodePacket(P2PNode server, P2PPacket packet); // Node-management packet (AKA: X-fer, assign, ect)

        void handleDataServerPacket(P2PNode server, P2PPacket packet);
        void handleCpuServerPacket(P2PNode server, P2PPacket packet);


        // connection handles
        void handleP2PServerDisconnect(P2PNode server); // P2P Server disconnects... (Re-connect to Lk-1 server)
};

#endif /*P2PLCLIENT_H_*/
