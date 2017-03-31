//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PREGISTER_SERVER_H_
#define P2PREGISTER_SERVER_H_

enum P2PSERVERTYPE {P2PST_MAINS, P2PST_CPU, P2PST_GPU, P2PST_DATA};

class P2PRegisterServer : public Packet {
    public:
        P2PRegisterServer(char* data) {
            id=60230;
            union {
                int in[2];
                long l;
            } p;
            p.in[0] = (int)data[0];
            p.in[1] = (int)data[1];
            serverPeerID = p.l;
            serverType = (P2PSERVERTYPE)data[3];
        }

        long getServerPeerID() {
            return serverPeerID;
        }
        P2PSERVERTYPE getServerType() {
            return serverType;
        }
    private:
        long serverPeerID;
        P2PSERVERTYPE serverType;
};

#endif
