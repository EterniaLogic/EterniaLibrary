#include "PacketChannel.h"

PacketChannel::PacketChannel(SockClient* cli, unsigned short id){
    this->id = id;
    this->client = cli;
}

PacketChannel::PacketChannel(){}
PacketChannel::~PacketChannel(){}



// internal
// received packet data, add to queue
void PacketChannel::addRecvPacketData(CharString *data){
    this->packetQ.push(data);
}


// send/retrieve data
void PacketChannel::sendPacket(CharString data){
    this->client->sendc(data);
}

// returns null if no new data.
CharString PacketChannel::recvPacket(){
    return *(CharString*)packetQ.pop();
}

// wait until there is new data.
CharString PacketChannel::recvWaitPacket(){
    while(packetQ.empty()){
        std::this_thread::sleep_for(std::chrono::microseconds(20000));
    }

    return *(CharString*)packetQ.pop();
}


