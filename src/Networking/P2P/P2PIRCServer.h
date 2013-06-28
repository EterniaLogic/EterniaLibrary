#ifndef P2PIRCSERVER_H_
#define P2PIRCSERVER_H_

#include "P2PInc.h"

class P2PIRCServer
{
public:
	static P2PIRCServer current;
	P2PIRCServer();
	virtual ~P2PIRCServer();
	
	void handlesIRCPacket(P2PNode client, P2PPacket packet); // Manages range of packet (May contact L1+ ir massive IRC)
	void sendIRCPacket(P2PNode client, P2PPacket packet);
};

#endif /*P2PIRCSERVER_H_*/
