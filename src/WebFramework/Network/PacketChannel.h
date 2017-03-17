#ifndef PACKET_CHANNEL_H_
#define PACKET_CHANNEL_H_

#include "../../Data/CharString.h"
#include "../../Data/Queue.h"

class PacketChannel{
private:
    Queue packetQ;
public:
    PacketChannel();
    
    // internal
    void addRecvPacketData(CharString* data); // received packet data, add to queue
    
    
    // send/retrieve data
    void sendPacket(CharString* data);
    CharString* recvPacket(); // returns null if no new data.
};

#endif
