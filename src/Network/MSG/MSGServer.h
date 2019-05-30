#ifndef MSG_SERVER_H
#define MSG_SERVER_H

class MSGServer;

#include "../../Data/Logger/Logger.h"
#include "../SocketServer.h"
#include "../../Math/Random.hpp"
class MSGClientChannel;
#include "MSGClientChannel.h"
class MSGClient;

#include "MSGClient.h"


// The Messaging Client/server system enables for a cloud of clients to inter-communicate.



class MSGServer : public SocketServer{
private:
public:
    LinkedList<MSGClient*> cclients; // saved clients
    LinkedList<MSGClient*> bservers; // other servers for synchronized data (like client ids, etc)
    LinkedList<MSGClientChannel*> channels; // absolute channels defined by clients
    
    // MSGServer servermsg = MSGServer(SS_TCP, "127.0.0.1", 9998, 1024, MSGSMODE_BROADCAST_ANY);
    MSGServer(SocketServerType serverType, CharString addr, int port, short buffer);
    
    void refreshClients(); // check for any disconnected clients
    MSGClient* getMSGClient(SockClient* c); // get from socket or 0x0
    MSGClient* getMSGClient(CharString identity); // get from id or 0x0
    MSGClientChannel* getMSGChannel(CharString channelname); // channel* or 0x0
    
    // only in-between broadcast servers
    void shareClientIPID(MSGClient* client);
    void addBroadcastServer(SockClient* c);
};

#endif
