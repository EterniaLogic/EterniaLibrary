#ifndef P2PCPUSERVER_H_
#define P2PCPUSERVER_H_

#include "P2PNode.h"
#include "P2PPacket.h"

class P2PCPUServer
{
public:
	static P2PCPUServer current;
	P2PCPUServer();
	virtual ~P2PCPUServer();
	
	void handleCPUServerPacket(P2PNode server, P2PPacket packet);
	void sendCPUServerPacket(P2PNode server, P2PPacket packet);
		
	void process(); // compress data stores
};

#endif /*P2PCPUSERVER_H_*/
