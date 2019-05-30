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

// Get a specific channel from the server
PacketChannel* ChannelledClient::getFreeChannel(){
    used.freeze();
    for(unsigned short i=0;i<65535;i++){
        bool t = true;
        // filter through used list to see if it contains the value
        for(int j=0;j<used.frozenlen;j++){
            if(i == used.frozen[j]){
                t = false;
            }
        }
        if(t){
            return getChannel(i);
        }
    }
    return 0x0;
}

 
  // claim a channel for this sub-program (to be used with getFreeChannel)
bool ChannelledClient::claimChannel(unsigned short id){
    used.add(id);
}
