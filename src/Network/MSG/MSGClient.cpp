#include "MSGClient.h"

// Static clients list
LinkedList<MSGClient*> MSGClient::mclients = LinkedList<MSGClient*>();
Math::Random MSGClient::r = Math::Random(time(0x0));

void _clientHandler_MSGCLIENT(CharString dataIn, CharString &dataOut, SockClient* client, void* d){
    // client handler for recieving data
    if(dataIn.getSize() <= 2) return;
    CharString l = "[MSGClient] handler: ";
    l+=dataIn;
    Logger::GLOBAL.log(l);
    
    MSGClient* mclient = 0x0;
    bool clientside = client->clientside;
    if(clientside){
        mclient = MSGClient::getOrCreateClient(client);
    }else{ // serverside
        if(d != 0x0){
            MSGServer* serv = (MSGServer*)d;
            mclient = serv->getMSGClient(client);
        }else{ // error? server not in (void*)d
            cout << "msgclient handler error: serverside, but couldn't get server class." << endl;
            return;
        }
    }
    
    // ID here is a message client's identity (assigned by server upon connect)
    if(dataIn.startsWith("id:")){ // server sends client new identity
        // id!
        LinkedList<CharString> s = dataIn.split(":");
        mclient->identity = s[1];
        
        CharString l2 = "[MSGClient] assigned new id ";
        l2+=mclient->identity;
        Logger::GLOBAL.log(l2);
    }else if(dataIn.startsWith("idname:")){ // other client's idname is client-specific, but stored on the broadcast servers
        // idname:NAME:ID
        // useful for finding out what ID goes where... "[Emailserver]" sent received an email. instead of "[-1020302]" sent an email.
    }else if(dataIn.startsWith("channel:publish:")){ // channel publish data (to here!)
        // channel:publish:CHANNAME:messsage:ID
    }else{
        // nothing, do not use raw data!
    }
    
    //dataOut = "received"; // report that the packet was received?
}

MSGClient::MSGClient(SockClient* _socketClient){
    serverclients.add(_socketClient);
    clientside = false;
    isbserver = false;
}

MSGClient::MSGClient(){
    clientside = false;
    isbserver = false;
}

MSGClient::~MSGClient(){}



bool MSGClient::hasBroadcastClient(SockClient* cli){ // even if the server has a client, it is stored in serverclients
    return serverclients.contains(cli);
}

// [SERVER-ONLY]
void MSGClient::sendNewIdentity(){
    if(clientside) return;
    if(serverclients.size() == 0) return;
    
    
    
    SockClient* client = getFirstBroadcastServer();
    //cout << "[BROADCAST] giving client (" << client->getAddr() << ") new ID" << endl;
    CharString l = "[BROADCAST] giving client (";
    l+=client->getAddr();
    l+=":";
    l+=client->port;
    l+=") new ID";
    Logger::GLOBAL.log(l);
    
    CharString idstr = "id:";
    CharString newid = CharString::ConvertFromLong(r.nextLong());
    idstr += newid;
    
    this->identity = newid;
    bool sent = client->sendc(idstr); // send back data to client upon it's connection to this server.
}


MSGClientChannel* MSGClient::subscribe(CharString messagechannel, void (*_message_handler_func)(CharString message)){
    if(!clientside) return 0x0;
    // subscribe to a channel if not already subscribed
    LinkedListIterator<MSGClientChannel*> chit = subChannels.getIterator();
    while(chit.hasNext()){
        MSGClientChannel* channel = chit.next();
        if(channel->channelname.compare(messagechannel)){
            return channel;
        }
    }
    
    // not connected to channel, connect up.
    // server tacks on this client's identity later on when it redistributes the message
    CharString packetmsg = "channel:subscribe:";
    packetmsg += messagechannel;
    MSGClientChannel* chanx = new MSGClientChannel(this, messagechannel);
    chanx->message_handler_func = _message_handler_func;
    subChannels.add(chanx);
    sendb_all(packetmsg); // send to all broadcast servers
    
    cout << "[MSGClient " << identity << "] Subscribed to channel " << messagechannel << endl;
}

void MSGClient::unsubscribe(CharString messagechannel){
    if(!clientside) return;
    // subscribe to a channel if not already subscribed
    LinkedListIterator<MSGClientChannel*> chit = subChannels.getIterator();
    while(chit.hasNext()){
        MSGClientChannel* channel = chit.next();
        if(channel->channelname.compare(messagechannel)){
            // exists, unsubscribe
            CharString packetmsg = "channel:unsubscribe:";
            packetmsg += messagechannel;
            sendb_all(packetmsg); // send to all broadcast servers
            channel->message_handler_func = 0x0; // remove function to prevent others from using it
            subChannels.remove(channel);
            
            cout << "[MSGClient " << identity << "] Unsubscribed channel " << messagechannel << endl;
            return; // break out.
        }
    }
    
    // not connected to channel, do nothing here.
}

void MSGClient::submitmessage(CharString messagechannel, CharString message){
    if(!clientside) return;
}


void MSGClient::connect_add_broadcast(SocketClientType ctype, CharString addr, short port, int buffersize, bool IPv6){
    if(!clientside) return;
    SockClient* c = new SockClient();
    c->_clientHandler = &_clientHandler_MSGCLIENT;
    c->clientside = true;
    c->connectc(ctype, addr.get(), port, buffersize, IPv6, _clientHandler_MSGCLIENT);
    serverclients.add(c);
    clientside = true;
}



// send message to all broadcast servers
void MSGClient::sendb_all(CharString message){ 
    if(!clientside) return;
    LinkedListIterator<SockClient*> cit = serverclients.getIterator();
    while(cit.hasNext()){
        SockClient* c = cit.next();
        if(c != 0x0)
            c->sendc(message);
    }
}

// send message to random broadcast server
void MSGClient::sendb_random(CharString message){
    if(!clientside) return;
    SockClient* c = getRandomBroadcastServer();
    if(c != 0x0)
        c->sendc(message);
}

SockClient* MSGClient::getFirstBroadcastServer(){
    if(serverclients.size() == 0) return 0x0;
    return serverclients[0];
}

// get a random broadcast server from list to help prevent flooding
SockClient* MSGClient::getRandomBroadcastServer(){
    if(serverclients.size() == 0) return 0x0;
    Math::Random r;
    int servc = r.nextInt(0, serverclients.size()-1);
    return serverclients[servc];
}

// determines if all broadcast servers are still connected. If not, attempt reconnect...
//  if there is no connection, then just keep dead.
bool MSGClient::checkBroadcastAlive(){
    LinkedListIterator<SockClient*> cit = serverclients.getIterator();
    bool alive=false;
    
    while(cit.hasNext()){
        SockClient* c = cit.next();
        if(!c->alive){
            c->reconnect(); // attempt reconnect...
        }else{
            alive=true;
        }
    }
    
    return alive;
}




///// STATIC
MSGClient* MSGClient::connect_broadcast(SocketClientType ctype, 
                CharString addr, short port, int buffersize, bool IPv6){
    // connect assuming the server is a broadcast server of ? type.
    // type is returned from the server (ANY, INTERCONNECT, P2PCONNECTOR)
    MSGClient* clientx = new MSGClient();
    clientx->clientside = true;
    clientx->connect_add_broadcast(ctype, addr.get(), port, buffersize, IPv6);
    
    
    return clientx;
}

MSGClient* MSGClient::getOrCreateClient(SockClient* _socketClient){ // initializer
    LinkedListIterator<MSGClient*> cit = mclients.getIterator();
    while(cit.hasNext()){
        MSGClient* c = cit.next();
        
        // Loop through broadcast servers for this msg client
        LinkedListIterator<SockClient*> scit = c->serverclients.getIterator();
        while(scit.hasNext()){
            SockClient* sc = scit.next();
            if(sc == _socketClient){
                return c;        
            }
        }
    }
    
    // couldn't find a client... create one
    MSGClient* cli = new MSGClient(_socketClient);
    mclients.add(cli);
    return cli;
}
