//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PNODECACHE_H_
#define P2PNODECACHE_H_

// Caches P2PNodes for later use. (i.e: IRC server, ect)
#include "P2PNode.h"
#include "../../../Data/LinkedList.hpp"

class P2PNodeCache {
    public:
        P2PNodeCache();
        virtual ~P2PNodeCache();
        LinkedList<P2PNode>* nodes();
        void cache(char* playername, P2PNode* l);
        P2PNode* find(char* playername);
} p2pNodeCache;

#endif /*P2PNODECACHE_H_*/
