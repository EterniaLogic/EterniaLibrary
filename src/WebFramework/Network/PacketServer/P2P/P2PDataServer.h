//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PDATASERVER_H_
#define P2PDATASERVER_H_

#include "P2PInc.h"

class P2PDataServer
{
public:
	static P2PDataServer current;
	P2PDataServer();
	virtual ~P2PDataServer();
	
	void handleDataServerPacket(P2PNode server, P2PPacket packet);
	void sendDataServerPacket(P2PNode server, P2PPacket packet);
	
	void compress(); // compress data stores
};

#endif /*P2PDATASERVER_H_*/
