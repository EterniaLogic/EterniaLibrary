#include "SockClient.h"

void SockClient::readhandler(){
    int n;
    const int buflen = bufferSize;
    char buffer[buflen];
    CharString writeto;
    
    Logger::GLOBAL.log("[SockClient]  reading thread started");
    
    while(alive){
        
        n = read(sockd, buffer, buflen);
        if (n < 0){
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            continue;
        }else if(n==0){
            Logger::GLOBAL.log("[SockClient] disconnected from server");
            if(disconnected != 0x0) disconnected(server, this);
            alive = false;
            return;
        }
        
        // post-clear extra data in packet... (Prevents extra cpu usage, clearer data stream)
        for(int i=n-1;i<buflen;i++) buffer[i] = 0;

        if(_clientHandler != 0x0 && n > 1) {
            //CharString d = (server->decryptor!=0x0) ? server->decryptor(CharString(buffer,n)) : CharString(buffer,n); // decrypt
            CharString d = CharString(buffer,n); // decrypt
            _clientHandler(d, writeto, this, exVAL);

            if(writeto.getSize() > 0){
                // segment packet if it is too large.
                sendc(writeto); // encryption in-client
            }
        }
    }
    
    Logger::GLOBAL.log("[SockClient] reading thread ended");
    alive = false;
}


SockClient::SockClient() {
#ifdef WINDOWSXX
    sockd = INVALID_SOCKET;
#endif
    this->alive = true;
    this->clientside = false;
    this->exVAL = 0x0; // set to null
    this->server = 0x0;
}

SockClient::SockClient(SocketServer* server){
#ifdef WINDOWSXX
    sockd = INVALID_SOCKET;
#endif
    this->alive = true;
    this->clientside = false;
    this->exVAL = 0x0; // set to null
    this->server = server;
}

// connect to a specific server
void SockClient::connectc(SocketClientType ctype,
                char* addr, short port, int buffersize, bool IPv6,
                void (*_clientHandler)(CharString dataIn, CharString &dataOut, SockClient* client, void* d)){
    this->ctype = ctype;
    this->addr = addr;
    this->port = port;
    this->bufferSize = buffersize;
    this->ipv6 = IPv6;
    this->_clientHandler = _clientHandler;
    this->async=true;
    this->clientside = true; // This is a client!
    
    this->connected = 0x0;
    this->disconnected = 0x0;
    this->encryptor = 0x0;

    CharString sl = "[SockClient] connecting to server ";
    sl += addr;
    sl += ":";
    sl += port;
    Logger::GLOBAL.log(sl);
    // socket setup is the same as the server.
    int ntype = SOCK_STREAM;
    int proto = 0;
    switch(this->ctype) {
        case SC_TCP:
            ntype = SOCK_STREAM;
            break;
        case SC_UDP:
            ntype = SOCK_DGRAM;
            break;
        case SC_ICMP:
            ntype = SOCK_DGRAM;
            proto = IPPROTO_ICMP;
            break;
    }

#ifdef LINUXXX
    // set up base data
    cli_addr = *(sockaddr_in*)calloc(sizeof(cli_addr),1);
    cli_addr.sin_family = IPv6 ? AF_UNSPEC : AF_INET;
    cli_addr.sin_addr.s_addr = INADDR_ANY;
    cli_addr.sin_port = htons((short)port);

    // establish a socket
    // connect socket
    sockd = socket(cli_addr.sin_family, ntype, proto); // << Defines socket type
    if (sockd < 0){
        cout << "Error opening socket..." << endl; cout.flush();
        return;
    }
    
    // set pton
    if(inet_pton(cli_addr.sin_family, addr, &cli_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return;
    } 
    
    
    //Logger::GLOBAL.log("[SockClient] pton done");

    // connect to server
    
    if( connect(sockd, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return;
    } 
    
    Logger::GLOBAL.log("[SockClient] connected");

    // start a data thread, if async
    if(_clientHandler != 0x0){
        if(async){
            clientthread = std::thread(&SockClient::readhandler, this);
        }else{
            readhandler();
        }
    }
#endif
}

bool SockClient::testAlive(){
#ifdef LINUXXX
    int error = 0;
    socklen_t len = sizeof (error);
    int retval = getsockopt (sockd, SOL_SOCKET, SO_ERROR, &error, &len);
    
    if (retval != 0) {
        /* there was a problem getting the error code */
        fprintf(stderr, "error getting socket error code: %s\n", strerror(retval));
        return false;
    }

    if (error != 0) {
        /* socket has a non zero error status */
        fprintf(stderr, "socket error: %s\n", strerror(error));
        return false;
    }
#endif    
    return true;
}

void SockClient::disconnect(){
    if(!alive) return;
#ifdef LINUXXX
    if(sockd > 0){
        shutdown(sockd, 2); // full socket dc
    }
#else defined(WINDOWSXX)
    closesocket(socketfd);
    WSACleanup();
#endif
}


void SockClient::reconnect(){
    
    disconnect();
    connectc(ctype, addr, port, bufferSize, ipv6,_clientHandler);
}

// if connected, send out a message
// returns false if not connected or error.
// auto-splits large messages larger than buffer.
bool SockClient::sendc(CharString message){
    CharString emsg = (encryptor!=0x0) ? encryptor(message) : message; // Apply encryption
    if(emsg.getSize() <= 2) return false;
    //cout << "Send message(" << emsg.getSize() << ")" << emsg.get() << endl;
    cout << "Send message(" << emsg.getSize() << ")"<< endl;

    int flags=0;
    int looptimes=1;
    int i, msgret, msgsize;
    char* msg;
#ifdef LINUXXX
     if(!testAlive()){
         // uh...
         return false;
     }
    
    if(ctype == SC_TCP){
        //msgret = send(sockd, message.get(), message.getSize(), flags);
        //cout << "Pre-write SC_TCP " << emsg.getSize() << endl;
        if(testAlive())
            msgret = write(sockd, emsg.get(), emsg.getSize());
        //cout << "post-write" << endl;
    }else{
        socklen_t addrlen = sizeof(struct sockaddr_in);
        //msgret = sendto(sockd, emsg.get(), emsg.getSize(), &cli_addr, address);
    }
    // detect error
    if(msgret == -1) return false;
#endif
    return true;
}

CharString SockClient::getAddr(){
    return addr;
}
