#ifndef P2PNODEPACKET_H_
#define P2PNODEPACKET_H_

#include "../P2PInc.h"

enum P2PNodePacketType {resolve, manage};

class P2PNodePacket : P2PPacket{
public:
	P2PNodePacketType type;
};

#endif /*P2PNODEPACKET_H_*/
