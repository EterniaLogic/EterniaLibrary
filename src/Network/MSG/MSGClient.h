#ifndef MSG_CLIENT_H
#define MSG_CLIENT_H

#include "../SockClient.h"
#include "../../Math/Random.hpp"
#include "MSGClientChannel.h"
#include "../../Data/Logger/Logger.h"
class MSGClient;
class MSGServer;
#include "MSGServer.h"


class MSGClient{
private:
    static LinkedList<MSGClient*> mclients;
    static Math::Random r;
public:
    LinkedList<SockClient*> serverclients; // [CLIENT] multiple MSGServers broadcasts
    LinkedList<MSGClientChannel*> subChannels; // subscribed channels
    CharString identity; // id string for this client (servertype specific if used)
    bool clientside;
    bool isbserver; // is another broadcast server interconnect?

    // constructors
    MSGClient(SockClient* _socketClient);
    MSGClient(); // for connectc(...);
    virtual ~MSGClient();
       
    // [SHARED]
    bool hasBroadcastClient(SockClient*); // even if the server has a client, it is stored in serverclients
    
    // [SERVER-ONLY]
    void sendNewIdentity();
    
    // [CLIENT] Client available messaging functions
    MSGClientChannel* subscribe(CharString messagechannel, void (*message_handler_func)(CharString message)); // subscribe("data", messageRecieveFunction);
    void unsubscribe(CharString messagechannel); // subscribe("data", messageRecieveFunction);
    void submitmessage(CharString messagechannel, CharString message); // pushes to a specific channel via connector server
    
    
    // [CLIENT] Multi-broadcast server settings
    void connect_add_broadcast(SocketClientType ctype, CharString addr, short port, int buffersize, bool IPv6);
    void sendb_all(CharString message); // send message to all broadcast servers
    void sendb_random(CharString message); // send message to ranodm broadcast server
    SockClient* getFirstBroadcastServer();
    SockClient* getRandomBroadcastServer(); // get a random broadcast server from list to help prevent flooding
    bool checkBroadcastAlive(); // determines if all broadcast servers are still connected. If not, attempt reconnect... if there is no connection, then just keep dead.
        
    
    // Connect to a broadcast server
    static MSGClient*  connect_broadcast(SocketClientType ctype, CharString addr, short port, int buffersize, bool IPv6);
    static MSGClient*  getOrCreateClient(SockClient* _socketClient); // initializer
};

#endif
