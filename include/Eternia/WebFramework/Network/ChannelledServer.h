#ifndef CHANNELLED_SERVER_H
#define CHANNELLED_SERVER_H

#include "SocketServer.h"
#include "PacketChannel.h"
#include "ChannelledClient.h"

// The channelled server allows for specific channels based on initial 2-byte value.

class ChannelledServer : public SocketServer{
private:
public:
    void (*_clientHandlerCH)(ChannelledClient*); // channelled data
    
    ChannelledServer(SocketServerType serverType, char* addr, int port, short buffer, void (*handler)(ChannelledClient*));

};

#endif
