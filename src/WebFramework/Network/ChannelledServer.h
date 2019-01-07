#ifndef CHANNELLED_SERVER_H
#define CHANNELLED_SERVER_H

#include "SocketServer.h"
#include "PacketChannel.h"
#include "ChannelledClient.h"

// The channelled server allows for specific channels based on initial 2-byte value.

class ChannelledServer : public SocketServer{
private:
public:
    void (*handler)(ChannelledClient*, PacketChannel* channel); // channelled data
    
    ChannelledServer(SocketServerType serverType, CharString addr, int port, short buffer, void (*handler)(ChannelledClient*, PacketChannel* channel));
    
    ChannelledClient* getChannelledClient(SockClient* cli);
    
    LinkedList<ChannelledClient*> cclients;
};

#endif
