#include "P2PNode.h"

P2PNode::P2PNode(P2PNodeType t, char* ip_, int port_)
{
	type = t;
	ip = ip_;
	port = port_;
}

P2PNode::~P2PNode()
{
}
