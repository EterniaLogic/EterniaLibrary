#ifndef CHANNELLED_SERVER_H
#define CHANNELLED_SERVER_H

#include "SocketServer.h"
#include "PacketChannel.h"

// The channelled server allows for specific channels based on initial 2-byte value.

class ChannelledServer : public SocketServer{
private:
public:
    ChannelledServer(SocketServerType serverType, CharString addr, int port);

};

#endif
