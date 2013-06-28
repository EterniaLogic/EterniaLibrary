#ifndef P2PLSERVER_H_
#define P2PLSERVER_H_

#include "P2PInc.h"

class P2PLServer
{
public:
	static P2PLServer current;
	P2PLServer();
	virtual ~P2PLServer();
	
	int level = 0; // server level (or L), only changed if participating in P2P. *cough* most likely to happen.
	P2PNode* neighbors; // Neighbors on this L Level. (AKA, boundary partners)
	P2PNode* clients; // E-Client player, Potential node.
	P2PNode* subNodes; // Sub L Nodes (May come in pairs based on pop. density)
	P2PBoundaries boundaries; // handles players within these bondaries.
	
	// direct server assigns
	void assignLServer(P2PNode player); // will subdivide this server's inner boundary futher.
	void assignDataServer(P2PNode player);
	void assignCpuServer(P2PNode player);
	void assignIRCServer(P2PNode player); // server that manages IRC chats between players.
	void assignStreamServer(P2PNode player); // Streams high-density audio or video.
	
	// assign to clients
	void assignClient(P2PNode player);
	
	// send to sub-node
	void assignLClient(P2PNode player);
	void redistributeBoundaries(); // If there have been changes to boundaries, distribute them.
	
	// Player transfers help manage player density Per dynamic sector.
	void sendPlayerTransfer(P2PNode player, P2PNode server);
	
	// Proximity client connection (Players close to each other? Connect them up!)
	void proximityTest(P2PNode player, P2PNode farplayer);
	
	// Primary handles
	void handlePacket(P2PNode player, P2PPacket packet); // first-stop for P2P Server-based packets
	void handleGamePacket(P2PNode player, P2PPacket packet); // certain game packets can be processed here.
	void handleConnectPacket(P2PNode player, P2PPacket packet); // ASSIGN new clients.
	
	// Sub-servers
	void handleCPUPacket(P2PNode player, P2PPacket packet); // Sim data from CPU server
	void handleDataPacket(P2PNode player, P2PPacket packet); // Compress data from Data server
	void handleIRCPacket(P2PNode player, P2PPacket packet); // handle IRC packet
	void handleStreamPacket(P2PNode player, P2PPacket packet); // handle Video/Audio packet
	
	void handleMainPacket(P2PNode player, P2PPacket packet); // handles packet from main server *whoa!*
	void handlePreNodePacket(P2PNode server, P2PPacket packet); // handles server a tier higher then this one, used for distrobutions, ect... Prevents fraud connections
	void handleSubNodePacket(P2PNode player, P2PPacket packet); // handles sub-node's packet data.
	
	// Connection handles
	void handleClientDisconnect(P2PNode player); // client disconnects
	void handleSubNodeDisconnect(P2PNode player); // Lk+1 disconnects
	
	// Co-LServer handles
	void handleCoServerPacket(P2PNode coserver, P2PPacket packet); // multiple servers managing heavy load?
	
	// Questions from prequel server (Server above)
	void handleNewBoundaries(P2PNode server, P2PPacket packet); // Get new node boundaries if they exist.
	void handleTransfer(P2PNode NewServer, P2PPacket);
};

#endif /*P2PLSERVER_H_*/
