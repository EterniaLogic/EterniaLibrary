#include "ChannelledServer.h"

void csClientHandler(CharString* dataIn, CharString* dataOut, void* instance){
    // handle packets. First 2 bytes on the packet are the channel to use.
    ChannelledServer *serv = (ChannelledServer*)instance;

    if(dataIn->getSize() > 2){
        char* val = dataIn->get();
        short channel = ((short)val[1]) + ((short)val[0])<<4;

        cout << "Received packet for channel: " << channel << endl;
    }
}


ChannelledServer::ChannelledServer(SocketServerType serverType, char* addr, int port, short buffer, void (*handler)(ChannelledClient*)){
    // place a client handler
    this->bufferSize = buffer;
    this->port = port;
    this->address = addr;
    this->stype = serverType;
    this->_clientHandler = csClientHandler;
    this->_clientHandlerCH = handler;
    this->exVAL = this;
}
