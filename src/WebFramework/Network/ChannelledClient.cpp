#include "ChannelledClient.h"

ChannelledClient::ChannelledClient(){}
ChannelledClient::~ChannelledClient(){}


// Get a specific channel from the server
PacketChannel* ChannelledClient::getChannel(short id){
    if(id < 0 || id > 65535) return 0x0;

    return &(channels[(const int)id]);
}
