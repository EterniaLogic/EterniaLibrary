#include "SockClient.h"

SockClient::SockClient() {
#ifdef WINDOWSXX
    sockd = INVALID_SOCKET;
#endif
    this->alive = true;
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
    
    this->connected = 0x0;
    this->disconnected = 0x0;
    this->encryptor = 0x0;

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
    /*serv_addr = *(sockaddr_in*)calloc(sizeof(serv_addr),1);
    serv_addr.sin_family = IPv6 ? AF_UNSPEC : AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((short)port);*/

    // establish a socket
    // connect socket
    sockd = socket(IPv6 ? AF_UNSPEC : AF_INET, ntype, proto); // << Defines socket type
    if (sockd < 0){
        cout << "Error opening socket..." << endl;
        return;
    }

    // connect to server

    // start a data thread, if async
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

// if connected, send out a message
// returns false if not connected or error.
// auto-splits large messages larger than buffer.
bool SockClient::sendc(CharString message){
    CharString emsg = (encryptor!=0x0) ? encryptor(message) : message; // Apply encryption
    //cout << "Send message" << endl;
    //cout << emsg.get() << endl;

    int flags=0;
    int looptimes=1;
    int i, msgret, msgsize;
    char* msg;
#ifdef LINUXXX
     if(!testAlive()){
         // uh...
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
