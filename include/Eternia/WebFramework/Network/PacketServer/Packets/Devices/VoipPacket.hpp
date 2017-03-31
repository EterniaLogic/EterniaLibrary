//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef VOIPPACKET_H_
#define VOIPPACKET_H_

#include "../Packet.hpp"

// a voice over ip packet requires a data sending set.
// Max out MTU (1500) per packet. 1500-4 = [1496 bits]
// fortunately, this is just a skeleton data packet.

class VoipPacket : public Packet {
    public:
        // TRANS
        VoipPacket(long FromID, long ToID, char* data) {
            fromID = FromID;
            toID = ToID;
            dat = data;
            union {
                long FID;
                long TID;
                char* DATA;
                char* d;
            } p;
            p.FID = FromID;
            p.TID = ToID;
            p.DATA = data;
            RAW = p.d;
        }


        // RECV
        VoipPacket(char* data) {
            RAW = data;
        }

        char* getRAW();
    private:
        long fromID;
        long toID;
        char* dat;
};


#endif
