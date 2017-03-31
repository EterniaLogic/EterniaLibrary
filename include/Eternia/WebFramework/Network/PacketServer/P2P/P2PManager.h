//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PMANAGER_H_
#define P2PMANAGER_H_

#include "P2PInc.h"



class P2PManager {
    public:
        P2PManager();
        virtual ~P2PManager();
        int GlobalMaxSubClients; // Global max # of clients.
        int GlobalMinSubClients; // max # of clients before a sub-node is created.

        int MaxSubNodes; // Max # of sub-nodes to manage.
        int MinSubNodes; // Max # of sub-nodes to manage.

        int GetP2PPort(); // determines if this computer can become a P2P Server. If so, port above -1 will be assigned.

        // connection
        P2PLClient connectP2PLServer(P2PNode server);


        // handles
        void handleP2PPacket(P2PNode player);
};

#endif /*P2PMANAGER_H_*/
