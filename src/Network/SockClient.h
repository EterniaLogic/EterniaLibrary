#ifndef SCLIENT_H_
#define SCLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWSXX
#endif

#ifdef __linux__ || __unix__
#define LINUXXX
#endif

#ifdef WINDOWSXX
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#elif defined(LINUXXX)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#elif defined(__APPLE__)

#endif


class SockClient;
class SocketServer;
#include "SocketServer.h"

#include "../Data/CharString.h"
#include "../Data/Logger/Logger.h"
using namespace std;

enum SocketClientType {SC_TCP, SC_UDP, SC_ICMP};

#if __linux__ || __unix__
struct sockaddr_un {
    sa_family_t sun_family;               /* AF_UNIX */
    char        sun_path[108];            /* pathname */
};
#endif

class SockClient {
protected:
    bool ipv6;
    int bufferSize;
    
    SocketClientType ctype;
    void readhandler();
    
public:
    SockClient();
    SockClient(SocketServer* server); // server-sided client
    void* exVAL;
    bool async;
    bool clientside; // only true when using connectc(...), otherwise assumes that this is a server's client
    int sockd, port;
    char* addr;
    SocketServer* server; // only on server-side
    
    
    void (*connected)(SocketServer*,SockClient*);
    void (*disconnected)(SocketServer*,SockClient*);
    CharString (*encryptor)(CharString); // encrypting function pre-send
    
#ifdef LINUXXX
    socklen_t address;
    struct sockaddr_in cli_addr;
#endif

    bool alive;
    std::thread clientthread;
    
    bool testAlive(); // test if the connection is alive...

    // handler for receiving data
    void (*_clientHandler)(CharString dataIn, CharString &dataOut, SockClient* client, void* d); 
    
    // connect to a specific server
    void connectc(SocketClientType ctype, 
                char* addr, short port, int buffersize, bool IPv6,
                void (*handler)(CharString dataIn, CharString &dataOut, SockClient* client, void* d));
    void disconnect();
    
    void reconnect();
    
    CharString getAddr(); // returns IP address
    
    // if connected, send out a message
    // returns false if not connected or error.
    bool sendc(CharString message);
};

#endif
