#include "MSGServer.h"

void _msgClientHandler_ANY_recv(MSGServer *serv, MSGClient* cli, CharString dataIn, CharString &dataOut){
    // handles any message type.
    
    if(dataIn.startsWith("channel:publish:")){ // channel publish data (to here!)
        // channel:publish:CHANNAME:DATA
        LinkedList<CharString> c = dataIn.split(":");
        // +":id" when sent to other channels
        MSGClientChannel* chan = serv->getMSGChannel(c[2]);
        if(chan != 0x0){
            CharString pack = dataIn;
            pack += ":";
            pack += cli->identity;
            chan->distributemessagepacket(pack); // send out the goods
        }
        
    }else if(dataIn.startsWith("channel:subscribe:")){ // client subscribes to channel
        // channel:subscribe:CHANNAME
    }else if(dataIn.startsWith("channel:unsubscribe:")){ // client unsubscribes from channel
        // channel:unsubscribe:CHANNAME
    }else   if(cli->isbserver) { // Is another broadcast server???
        
        if(dataIn.startsWith("newid:")){ // sent from other server
            // newid:IP:ID
        }else if(dataIn.startsWith("newchannel:")){ // new messaging channel
            // newchannel:NAME
        }else  if(dataIn.startsWith("newsubscriber:")){ // new subscriber for the channel
            // newsubscriber:NAME:ID
        }else  if(dataIn.startsWith("unsubscriber:")){ // channel unsub
            // unsubscriber:NAME:ID
        }
    }
}


void _msgClientHandler(CharString dataIn, CharString &dataOut, SockClient* client, void* instance){
    // handle packets. First 2 bytes on the packet are the channel to use.
    MSGServer *serv = (MSGServer*)instance;

    if(dataIn.getSize() > 2){
        
        // loop through and manage clients
        MSGClient* cli = serv->getMSGClient(client);
        
        if(cli != 0x0){
            _msgClientHandler_ANY_recv(serv, cli, dataIn, dataOut);
        
            //PacketChannel* channelx = cli->getChannel(channel);
            //channelx->addRecvPacketData(new CharString(dataIn.get(), dataIn.getSize()));
            //serv->handler (cli, channelx);
        }
    }
}

void _msgClientConnected(SocketServer* serv, SockClient* client){
    //cout << "Client connected" << endl;
    MSGServer* server = (MSGServer*)serv;
    MSGClient* cli = server->getMSGClient(client);
    cli->sendNewIdentity(); // sends "id:-9123993293" to client (numbers there are just random long)
}

MSGServer::MSGServer(SocketServerType serverType, CharString addr, int port, short buffer){
    // place a client handler
    this->bufferSize = buffer;
    this->port = port;
    this->address = addr;
    this->stype = serverType;
    this->_clientHandler = _msgClientHandler;
    this->exVAL = this; // server exVAL
    
    // external function events
    this->connected = &_msgClientConnected;
    this->disconnected = 0x0;
}


void MSGServer::refreshClients(){
    MSGClient* client = 0x0;
    
    LinkedList<MSGClient*> activeClients;
    
    // loop through clients
    LinkedListIterator<MSGClient*> msgcit = cclients.getIterator();
    while(msgcit.hasNext()){
        MSGClient* c = msgcit.next();
        
        // is an actual client?
        if(c != 0x0){
            if(c->checkBroadcastAlive()){ // quick check
                activeClients.add(c);
            }
        }
    }
    
    cclients.clear(); // clear old one
    cclients = activeClients;
}

MSGClient* MSGServer::getMSGClient(SockClient* cli){
    MSGClient* client = 0x0;
    
    LinkedList<MSGClient*> activeClients;
    
    refreshClients();
    
    // loop through clients
    LinkedListIterator<MSGClient*> msgcit = cclients.getIterator();
    while(msgcit.hasNext()){
        MSGClient* c = msgcit.next();
        if(c->hasBroadcastClient(cli)) // has a serverclient socket?
            client = c;
    }
    
    // found client? If not, add to list if it's alive.
    if(client == 0x0 && cli != 0x0){
        if(cli->alive){
            client = new MSGClient(cli);
            activeClients.add(client);
        }
    }
    
    cclients.clear(); // clear old one
    cclients = activeClients;
    
    return client;
}

MSGClient* MSGServer::getMSGClient(CharString identity){ // get from id
    refreshClients();
    
    // loop through clients
    LinkedListIterator<MSGClient*> msgcit = cclients.getIterator();
    while(msgcit.hasNext()){
        MSGClient* c = msgcit.next();
        
        // is an actual client?
        if(c != 0x0){
            if(c->identity.compare(identity)){
                return c;
            }
        }
    }
    
    // none!
    return 0x0;
}

// get channel
MSGClientChannel* MSGServer::getMSGChannel(CharString channelname){
    // loop through channels
    LinkedListIterator<MSGClientChannel*> msgcit = channels.getIterator();
    while(msgcit.hasNext()){
        MSGClientChannel* channel = msgcit.next();
        if(channel->channelname.compare(channelname)){
            return channel;
        }
    }
    
    // no channel by that name
    return 0x0;
}


// only in-between broadcast servers
void MSGServer::shareClientIPID(MSGClient* client){
    LinkedListIterator<MSGClient*> bit = bservers.getIterator();
    SockClient* sc = client->getFirstBroadcastServer();
    CharString msgpack = "newid:";
    msgpack += sc->getAddr();
    msgpack += ":";
    msgpack += client->identity;
    
    while(bit.hasNext()){
        MSGClient* bserver = bit.next();
        if(!bserver->isbserver) continue;
        
        SockClient* bsc = bserver->getFirstBroadcastServer();
        if(bsc != 0x0){
            bsc->sendc(msgpack);
        }
    }
}

void MSGServer::addBroadcastServer(SockClient* c){
    MSGClient* client = new MSGClient(c);
    client->isbserver = true;
    
    bservers.add(client);
}

