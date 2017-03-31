//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PREQUEST_PID_H_
#define P2PREQUEST_PID_H_

// An edge peer can request a PeerID of a user based on their username or unique identifier.
// Branch P2P Rails will use their unique lookup tables to find the id
// all rail servers have a full-sized char-name => ID conversion table.

class P2PRequestPID : public Packet {
    public:
        P2PRequestPID(char* iddata) {
            id = 21050;
            identifier = iddata;
        }

        // return identifier
        char* getIdentifier() {
            return identifier;
        }

    private:
        char* identifier;
};

#endif
