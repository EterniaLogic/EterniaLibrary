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
