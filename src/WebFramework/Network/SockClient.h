#ifndef SCLIENT_H_
#define SCLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

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
#elif defined(__APPLE__)

#endif




#include <thread>
#include "../../Data/CharString.h"
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
    int bufferSize, port;
    char* addr;
    SocketClientType ctype;
public:
    SockClient();
    void* exVAL;
    bool async;
    int sockd;
    
    void (*connected)(SockClient*);
    void (*disconnected)(SockClient*);
    CharString (*encryptor)(CharString); // encrypting function pre-send
    
#ifdef LINUXXX
    socklen_t address;
    sockaddr_in cli_addr;
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
    
    // if connected, send out a message
    // returns false if not connected or error.
    bool sendc(CharString message);
};

#endif
