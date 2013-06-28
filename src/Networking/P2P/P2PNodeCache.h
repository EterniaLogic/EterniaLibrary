#ifndef P2PNODECACHE_H_
#define P2PNODECACHE_H_

// Caches P2PNodes for later use. (i.e: IRC server, ect)
#include "P2PNode.h"
#include "../../Data/LinkedList.hpp"

class P2PNodeCache
{
public:
	P2PNodeCache();
	virtual ~P2PNodeCache();
	LinkedList<P2PNode>* nodes();
	void cache(char* playername, P2PNode* l);
	P2PNode* find(char* playername);
} p2pNodeCache;

#endif /*P2PNODECACHE_H_*/
