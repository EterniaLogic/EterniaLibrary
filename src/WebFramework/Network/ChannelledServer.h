#ifndef CHANNELLED_SERVER_H
#define CHANNELLED_SERVER_H

#include "SocketServer.h"
#include "PacketChannel.h"

// The channelled server allows for specific channels based on initial 2-byte value.

class ChannelledServer : public SocketServer{
private:
    PacketChannel channels[65536];
    
public:
    ChannelledServer(int port, CharString addr);
    
    PacketChannel* getChannel(int id);
};

#endif
