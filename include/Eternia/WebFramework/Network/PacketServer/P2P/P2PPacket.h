//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PPACKET_H_
#define P2PPACKET_H_

#include "P2PNode.h"

class P2PPacket {
    public:
        P2PPacket();
        virtual ~P2PPacket();

        //sends packet to destination P2PNode (Quick-send)
        // If P2PNode is not directly connectable, access node via L server.

        P2PNode sender;
        char* data;
        P2PNode destination;

        // basic P2P packet structures:
        // IRC|99.99.99.99:55555|10.6.7.80:3490|[data]      //Chat packet
        // STREAM|99.99.99.99:55555|10.5.7.85:32490|[data]  //File/Vid/Audio packet
        // DATA|99.99.99.99:55555|GS|[data]                 //Data packet directed towards game server.
        // GAME|99.99.99.99:55555|4.5.7.32:31450|[data]
        // NODE|99.99.99.99:55555|12.68.98.46:30320|[data]

        // STREAM|99.99.99.99:55555|PLAYER:dread|[data]     //non-Direct player sending
        // IRC|99.99.99.99:55555|PLAYER:dread|[data]        //non-Direct player IRC chat

        // Advanced Node-Based P2P Player finding: (NODE|~~~|[data])
        // POLL_USER|playername         // Goes up in levels until it finds a server that contains the player. Received packet is:
        // POLL_RETURN|playername|[LADDR] // returns the poll with a direct LADDR for the player.

        // Advanced Node-Based P2P IRC:
        // IRC_SEND|playername|msg|type|range       //IRC msg sent from player for range size (range determines the "level")
        // IRC_RECV|playername|msg|chattype         //IRC receive message

        void attemptDirect();
};

#endif /*P2PPACKET_H_*/
