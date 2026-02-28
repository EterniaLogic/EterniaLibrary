#ifndef SocketServer_H_
#define SocketServer_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <thread>

#ifdef _WIN64
   #define WINDOWSXX
#elif _WIN32
   #define WINDOWSXX
   #define _WIN32_WINNT 0x1000
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
        // define something for simulator
    #elif TARGET_OS_IPHONE
        // define something for iphone
    #else
        #define TARGET_OS_OSX 1
        // define something for OSX
    #endif
#elif __linux
    #define LINUXXX
#elif __unix // all unices not caught above
    #define LINUXXX
#elif __posix
    #define LINUXXX
#endif



//#include <math>

#ifdef WINDOWSXX
#define byte win_byte_override  // Rename 'byte' before including windows.h
#include <windows.h>
#undef byte                    // Restore 'byte' so C++ std::byte works again
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")

#elif defined(LINUXXX)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#elif defined(__APPLE__)

#endif

class SocketServer;
class SockClient;
#include "SockClient.h"
#include "../Data/LinkedList.hpp"
#include "../Data/CharString.h"

#define error(x) cout << x << endl; return;
#define BUFFER_SIZEX 256

using namespace std;

enum SocketServerType {SS_TCP, SS_UDP, SS_ICMP};

// Wrapper for the C++ socket server, help's discriminate TCP, UDP and ICMP while threading the client

// The SocketServer is the base for proceeding servers, such as HTML and socket servers.
// Handlers will be initially managed here, where multi-threading will handle the base server node and client nodes.
class SocketServer {
protected:
    short port;
    unsigned int socketfd;

    SocketServerType stype; // UDP, TCP or ICMP. Changes some of the control logic
    
#ifdef LINUXXX
    sockaddr_in serv_addr;
    socklen_t clilen;
#elif defined(WINDOWSXX)
    WSADATA wsaData;
    struct addrinfo *result = NULL;
    struct addrinfo hints;
#endif
    CharString address;
    bool started, async, ipv6;
    std::thread acceptorThread;
    void tcpConnectionAcceptor();
    

public:
    bool dolisten;
    int bufferSize;
    void* exVAL;
    LinkedList<SockClient*> clients;
    void (*connected)(SocketServer*,SockClient*);
    void (*disconnected)(SocketServer*,SockClient*);
    CharString (*encryptor)(CharString); // encrypting function pre-send
    CharString (*decryptor)(CharString); // decrypting function pre-recieve

    void (*_clientHandler)(CharString dataIn, CharString &reply, SockClient* client, void* exVAL); // Assigned handler for the client

    SocketServer();
    SocketServer(SocketServerType serverType,
                 CharString address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                 int port,
                 int bufferSize, // Packet buffer size
                 bool IPv6,
                 void (*clientHandler)(CharString dataIn, CharString &dataOut, SockClient* client, void* exVAL)); // dataIn is read-only, for dataOut use dataOut.set(char*), ex is just an extra parameter


    void startAsync(); // start server in another thread.
    void start(); // Start the server
    void Close();
};

#endif
