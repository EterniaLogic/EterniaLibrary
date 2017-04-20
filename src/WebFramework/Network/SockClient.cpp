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
                void (*_clientHandler)(CharString* dataIn, CharString* dataOut, void* d)){
    this->ctype = ctype;
    this->addr = addr;
    this->port = port;
    this->bufferSize = buffersize;
    this->ipv6 = IPv6;
    this->_clientHandler = _clientHandler;
    this->async=true;

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

// if connected, send out a message
// returns false if not connected or error.
// auto-splits large messages larger than buffer.
bool SockClient::sendc(CharString message){
    int flags=0;
    int looptimes=1;
    int i, msgret, msgsize;
    char* msg;
#ifdef LINUXXX
    if(message.getSize() > bufferSize){

        flags |= MSG_MORE;

        looptimes = floor((float)message.getSize() / (float)bufferSize);
    }

    for(i=0; i<looptimes;i++){
        if(i >= looptimes-1){
            flags=0;
            msgsize = (message.getSize() < bufferSize) ? message.getSize() : message.getSize() % bufferSize;
        }else{
            msgsize = (message.getSize() < bufferSize) ? message.getSize() : message.getSize();
        }

        msg = message.substr(i*bufferSize, msgsize).get();

        // send data
        if(ctype == SC_TCP)
            msgret = send(sockd, msg, msgsize, flags);
        //else msgret = sendto(sockd, msg, msgsize, addr, addrlen);

        // detect error
        if(msgret == -1) return false;
    }
#endif
    return true;
}
