#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
}

NetworkManager::~NetworkManager()
{
}

//manages the massive orchestra that is going to be performed.
//Contact forms:
//	GatewayServer (client)	[Manages save data, info, ect. Processes most requests in-between all servers]
//	LoginServer (client)	[Login to TRO through this. Grid-computed if required]
//	PeerServer (client)		[response-based server, redirects players to sub-node servers]
//			[[Can be expanded with multiple servers to handle much more data and clients]]
//	OLServer (none)			[Manages back-end RNPCs, simulates data for offline players. May be grid-computed]

//Peer-based:
//	DataServer (P2P)	[Compacts data, X-mits to main and sub servers. normally on top-level servers (L1-L2)]
//	CPUServer (P2P)		[simulates data for offline players, RPNPCs, WIRE, ect (directly connected to dataServer)]
//	L1Server (P2P)		[Level-1 (closest to main server)]
//	L2Server (P2P)		[Level-2 (sub-node of L1 server)] --Auto-Assigned by L1 if too many clients--
//	L3Server (P2P)		[Level-3 (sub-node of L2 server)] --Auto-Assigned by L2 if too many clients--
//	L4Server (P2P)		[Level-4 (sub-node of L3 server)] --Auto-Assigned by L3 if too many clients--
//	LnServer (P2P)		[Level-n (sub-node of Ln server)] --Auto-Assigned by L4+ if too many clients--
//	ENode	(P2P)		[normal player that isn't doing anything, normally connects to a L1, which refers to sub-branches]
//	FNode	(P2P)		[player that cannot open upnp ports to host. Anything :(]

//Ln server quits? Ln-1 server is contacted again to request for a slot.
//L1 server quits? L2 server becomes L1 server.
//entire L branch quits? Contact the Peer Server for a new branch to work off of. (constant connection)
// what does the L1 connect to? GatewayServer
