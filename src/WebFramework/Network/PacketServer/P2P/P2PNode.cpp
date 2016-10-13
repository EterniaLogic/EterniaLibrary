//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "P2PNode.h"

P2PNode::P2PNode(P2PNodeType t, char* ip_, int port_) {
    type = t;
    ip = ip_;
    port = port_;
}

P2PNode::~P2PNode() {
}
