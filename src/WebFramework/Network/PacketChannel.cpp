#include "PacketChannel.h"

PacketChannel::PacketChannel(){

}
PacketChannel::~PacketChannel(){
}

// internal
// received packet data, add to queue
void PacketChannel::addRecvPacketData(CharString *data){
    packetQ.push(data);
}


// send/retrieve data
void PacketChannel::sendPacket(CharString data){

}

// returns null if no new data.
CharString PacketChannel::recvPacket(){
    return *(CharString*)packetQ.pop();
}

CharString PacketChannel::recvWaitPacket(){
    while(packetQ.empty()){
        std::this_thread::sleep_for(std::chrono::microseconds(20000));
    }

    return *(CharString*)packetQ.pop();
}


