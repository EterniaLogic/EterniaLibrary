#include "ChannelledServer.h"

ChannelledServer::ChannelledServer(int port, CharString addr){
    // place a client handler
    
    
}

// Get a specific channel from the server
PacketChannel* ChannelledServer::getChannel(int id){
    if(id < 0 || id > 65535) return 0x0;
    
    return &(channels[(const int)id]);
}
