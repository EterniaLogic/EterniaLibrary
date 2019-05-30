#ifndef CHANNELLED_CLIENT_H
#define CHANNELLED_CLIENT_H

#include "../SockClient.h"
#include "PacketChannel.h"

// The channelled server allows for specific channels based on initial 2-byte value.
// Channel 0 is used to coordinate with other channels or whatever.

class ChannelledClient : public SockClient{
private:
    PacketChannel channels[65536];
    LinkedList<unsigned short> used;
public:
    ChannelledClient(SockClient* _socketClient);
    virtual ~ChannelledClient();
    
    SockClient* socketClient;

    PacketChannel* getChannel(unsigned short id);
    PacketChannel* getFreeChannel(); // get a channel that is open for use
    bool claimChannel(unsigned short id); // claim a channel for this sub-program (to be used with getFreeChannel)
};

#endif
