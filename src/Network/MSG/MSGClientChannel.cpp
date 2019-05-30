#include "MSGClientChannel.h"

MSGClientChannel::MSGClientChannel(MSGClient* _broadcastclient, CharString _channelname){
    this->broadcastclient = _broadcastclient;
    this->channelname = _channelname;
    message_handler_func = 0x0; // for CLIENT;
}

MSGClientChannel::~MSGClientChannel(){}


// send message from this client to other clients via P2P or through the interconnect broadcast server(s)
void MSGClientChannel::submitmessage(CharString message){ 
    SockClient* bc = broadcastclient->getRandomBroadcastServer();
    
    CharString packetmsg = "channel:submit:";
    packetmsg += channelname;
    packetmsg += ":";
    packetmsg += message;
    
    bc->sendc(packetmsg); // server-side tacks on :ID to end of message
}

// distributes a message across all subscribed clients
//  message already has
void MSGClientChannel::distributemessagepacket(CharString message){
    LinkedListIterator<MSGClient*> msgcit = subscribedclients.getIterator();
    
    
    while(msgcit.hasNext()){
        MSGClient* c = msgcit.next();
        SockClient* sc = c->getRandomBroadcastServer();
        if(sc != 0x0)
            sc->sendc(message);
    }
}

void MSGClientChannel::sub(MSGClient* cli){ // client subscribes
    if(!subscribedclients.contains(cli))
        subscribedclients.add(cli);
}

void MSGClientChannel::unsub(MSGClient* cli){ // client unsubscribes
    subscribedclients.remove(cli);
}
