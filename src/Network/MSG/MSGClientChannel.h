#ifndef MSG_CLIENT_CHAN_H
#define MSG_CLIENT_CHAN_H

#include "../SockClient.h"
class MSGClient;
class MSGClientChannel;
#include "MSGClient.h"

class MSGClientChannel{
private:
public:
    CharString channelname;
    MSGClient* broadcastclient; // {CLIENT} client connected to broadcast
    LinkedList<MSGClient*> subscribedclients; // {BROADCASTSERVER} list of clients that are subscribed
    
    void (*message_handler_func)(CharString message); // {CLIENT} handler for incoming message
    
    MSGClientChannel(MSGClient* broadcastclient, CharString channelname);
    virtual ~MSGClientChannel();
    
    // CLIENT
    // wraps message with 'channel:publish:MESSAGE:ID' (ID is from client)
    void submitmessage(CharString message); // send message from this client to other clients via P2P or through the interconnect broadcast server(s)
    
    // BROADCASTSERVER
    void distributemessagepacket(CharString messagepacket); // sends message to all subscribed clients.
    void sub(MSGClient*); // client subscribes
    void unsub(MSGClient*); // client unsubscribes
};

#endif
