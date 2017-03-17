#ifndef SocketServer_H_
#define SocketServer_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#elif defined(__linux__) || defined(__unix__)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#elif __APPLE__

#endif

#include <thread>
#include "SockClient.h"
#include "../../Data/LinkedList.hpp"
#include "../../Data/CharString.h"

#define error(x) cout << x << endl; return;
#define BUFFER_SIZEX 256

using namespace std;

enum SocketServerType {SS_TCP, SS_UDP, SS_ICMP};

// Wrapper for the C++ socket server, help's discriminate TCP, UDP and ICMP while threading the client

// The SocketServer is the base for proceeding servers, such as HTML and socket servers.
// Handlers will be initially managed here, where multi-threading will handle the base server node and client nodes.
class SocketServer {
private:
    int port, bufferSize;

    SocketServerType stype; // UDP, TCP or ICMP. Changes some of the control logic
#if defined(__linux__) || defined(__unix__)
    sockaddr_in serv_addr;
#endif
    char* address;
    bool started;
    std::thread acceptorThread;
    //void connectionAcceptor();
    void ClientHandler_(SockClient* tclient, std::thread thisthread);   // Pre-client handler, reads from the buffer
    
    

public:
    bool dolisten;
	int socketfd;
    LinkedList<SockClient> clients;
#if defined(__linux__) || defined(__unix__)
    socklen_t clilen;
#endif
    void (*_clientHandler)(CharString* dataIn, CharString* dataOut); // Assigned handler for the client

    SocketServer();
    SocketServer(SocketServerType serverType,
                 char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                 int port,
                 int bufferSize, // Packet buffer size
                 void (*clientHandler)(CharString* dataIn, CharString* dataOut)); // dataIn is read-only, for dataOut use dataOut.set(char*)

    void tcpConnectionAcceptor();

    void start(); // Start the server
    void Close();
};

#endif
