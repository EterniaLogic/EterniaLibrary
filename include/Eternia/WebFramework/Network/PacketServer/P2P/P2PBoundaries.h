//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PBOUNDARIES_H_
#define P2PBOUNDARIES_H_

// Each T-level is a reverse fractal inside the backbones.
// Boundaries are defined by the players inside of that fractal.
// The universe is essentially divided into 10-10,000 parts on startup.

class P2PBoundaries {
    public:
        P2PBoundaries();
        virtual ~P2PBoundaries();

        long x,y; // x, y coords
        long x1,y1; // other edge of boundary.

        long minsectorx; //Min sector boundaries (Prevents P2PLServers from going lower and forces them to Co-server)
        long minsectory;
};

#endif /*P2PBOUNDARIES_H_*/
