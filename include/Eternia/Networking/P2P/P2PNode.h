//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef P2PSUBNODE_H_
#define P2PSUBNODE_H_

enum P2PNodeType {Server,Client};

class P2PNode
{
public:
	P2PNode(P2PNodeType t, char* ip_, int port_);
	virtual ~P2PNode();
	
	P2PNodeType type;
	char* ip;
	int port;
	P2PNode* LServerList; //list of P2PNodes down the L-Server node line. (this is a client of *)
};

#endif /*P2PSUBNODE_H_*/
