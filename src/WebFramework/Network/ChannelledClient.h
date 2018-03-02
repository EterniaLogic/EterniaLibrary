#ifndef CHANNELLED_CLIENT_H
#define CHANNELLED_CLIENT_H

#include "SockClient.h"
#include "PacketChannel.h"

// The channelled server allows for specific channels based on initial 2-byte value.

class ChannelledClient : public SockClient{
private:
    PacketChannel channels[65536];
public:
    ChannelledClient(SockClient* _socketClient);
    virtual ~ChannelledClient();
    
    SockClient* socketClient;

    PacketChannel* getChannel(unsigned short id);
};

#endif
