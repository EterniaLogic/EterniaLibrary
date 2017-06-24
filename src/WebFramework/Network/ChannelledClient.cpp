#include "ChannelledClient.h"

ChannelledClient::ChannelledClient(SockClient* _socketClient){
    socketClient = _socketClient;
    for(int i=0;i<65536;i++){
        channels[i] = PacketChannel(_socketClient,i);
    }
}
ChannelledClient::~ChannelledClient(){}


// Get a specific channel from the server
PacketChannel* ChannelledClient::getChannel(unsigned short id){
    if(id < 0 || id > 65535) return 0x0;
    
    return &(channels[(const int)id]);
}
