//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef PASSAGE_PACKET_H_
#define PASSAGE_PACKET_H_ //woo!

#include "../Packet.hpp"

// Internal ROUTING system.
// A passage packet is used to send a peer-to-peer packet to a specific peer.
// In-between "Rail" Peers have LUT (Look up tables) that list what direction the packet should go. Only the closest Rail actually has the IP of a specific client.

class P2PPassagePacket : public Packet {
    public:
        P2PPassagePacket(long FROM, long TO, char* dat) {
            // set vars
            id = 7024;
            fromPeerID = FROM;
            toPeerID = TO;
            data = dat;

            // Get RAW
            union {
                long id;
                long l;
                long l2;
                char* d;
                char* out;
            } p;
            p.id = id;
            p.l = FROM;
            p.l2 = TO;
            p.d = dat;
            RAW = p.out;
        }

        P2PPassagePacket(char* dat) {
            // define RAW data
            id = 7024;
            union {
                long id;
                char* indat;
                char* out;
            } ss;
            ss.id = id;
            ss.indat = dat;
            RAW = ss.out;

            // set union for long ids
            union {
                int in[2];
                long l;
            } p,p2;

            // read for frompeerid
            p.in[0] = (int)dat[0];
            p.in[1] = (int)dat[1];
            fromPeerID = p.l;

            // read for topeerid
            p2.in[0] = (int)dat[2];
            p2.in[1] = (int)dat[3];
            toPeerID = p2.l;

            // read the rest of the packet into the data container
            data = (dat)+4;
        }

    private:
        long fromPeerID;
        long toPeerID;
        char* data;
};

#endif
