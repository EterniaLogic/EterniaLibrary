#ifndef PACKET_CHANNEL_H_
#define PACKET_CHANNEL_H_

#include "../../Data/CharString.h"
#include "../../Data/Queue.h"
#include "SockClient.h"

class PacketChannel{
private:
    Queue packetQ;
    SockClient* client;
    unsigned short id;
public:
    PacketChannel();
    PacketChannel(SockClient* cli, unsigned short id);
    virtual ~PacketChannel();

    // internal
    void addRecvPacketData(CharString *data); // received packet data, add to queue


    // send/retrieve data
    void sendPacket(CharString data); // don't wait around, send a message.
    
    CharString recvPacket(); // returns null if no new data.
    CharString recvWaitPacket(); // efficiently waits for a new packet. SYNC
};

#endif
