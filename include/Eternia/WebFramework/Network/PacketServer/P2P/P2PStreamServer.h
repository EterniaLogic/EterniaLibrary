//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PSTREAMSERVER_H_
#define P2PSTREAMSERVER_H_

#include "P2PInc.h"

class P2PStreamServer {
    public:
        static P2PStreamServer current;
        P2PStreamServer();
        virtual ~P2PStreamServer();

        /*
         * Redistributes video to other players. P2PLServer assigns a dynamic amount based on requirements.
         * Helps redistribute Patches to other players.
         * !!! Most players that can P2P Host will use this !!!
         */

        //handles
        void handleStreamPacket(P2PNode sender, P2PPacket packet);

        void sendStreamPacket(P2PNode player, P2PPacket packet);
};

#endif /*P2PSTREAMSERVER_H_*/
