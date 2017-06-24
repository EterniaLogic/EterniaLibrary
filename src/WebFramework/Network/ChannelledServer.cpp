#include "ChannelledServer.h"

void _csClientHandler(CharString dataIn, CharString &dataOut, SockClient* client, void* instance){
    // handle packets. First 2 bytes on the packet are the channel to use.
    ChannelledServer *serv = (ChannelledServer*)instance;

    if(dataIn.getSize() > 2){
        char* val = dataIn.get();
        unsigned short channel = ((unsigned short*)val)[0];
        dataIn.shiftLeft(2);
        
        cout << "Received packet for channel: " << channel << " data: '"<< dataIn.get() << "'" << endl;
        
        
        if(serv->handler != 0x0){
            // loop through and manage clients
            ChannelledClient* cli = serv->getChannelledClient(client);
            
            if(cli != 0x0){
                PacketChannel* channelx = cli->getChannel(channel);
                channelx->addRecvPacketData(new CharString(dataIn.get(), dataIn.getSize()));
                serv->handler (cli, channelx);
            }
        }
    }
}

ChannelledServer::ChannelledServer(SocketServerType serverType, char* addr, int port, short buffer, void (*handler)(ChannelledClient*, PacketChannel* channel)){
    // place a client handler
    this->bufferSize = buffer;
    this->port = port;
    this->address = addr;
    this->stype = serverType;
    this->_clientHandler = _csClientHandler;
    this->handler = handler;
    this->exVAL = this;
    
    // external function events
    this->connected = 0x0;
    this->disconnected = 0x0;
}

// internally test for active clients and maintain list.
ChannelledClient* ChannelledServer::getChannelledClient(SockClient* cli){
    ChannelledClient* client = 0x0;
    
    LinkedList<ChannelledClient> activeClients;
    
    // loop through clients
    cclients.freeze();
    for(int i=0;i<cclients.frozenlen;i++){
        ChannelledClient* c = cclients.frozen[i];
        
        // is an actual client?
        if(c != 0x0){
            // socket exists?
            if(c->socketClient != 0x0){
                // alive?
                if(c->socketClient->alive){
                    // is the client we want?
                    if(c->socketClient == cli)
                        client = c;
                    activeClients.add(c);
                }
            }
        }
    }
    
    // found client? If not, add to list if it's alive.
    if(client == 0x0 && cli != 0x0){
        if(cli->alive){
            client = new ChannelledClient(cli);
            activeClients.add(client);
        }
    }
    
    cclients.clear();
    cclients = activeClients;
    
    return client;
}
