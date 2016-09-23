#ifndef SocketServer_H_
#define SocketServer_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include "SockClient.h"
#include "../../Data/LinkedList.hpp"
#include "../../Data/CharString.h"

#define error(x) cout << x << endl; return;
#define BUFFER_SIZEX 256

using namespace std;

enum SocketServerType{SS_TCP, SS_UDP, SS_ICMP};

// Wrapper for the C++ socket server, help's discriminate TCP, UDP and ICMP while threading the client

// The SocketServer is the base for proceeding servers, such as HTML and socket servers.
// Handlers will be initially managed here, where multi-threading will handle the base server node and client nodes.
class SocketServer{
private:
	int port, bufferSize;
	
	SocketServerType stype; // UDP, TCP or ICMP. Changes some of the control logic
	sockaddr_in serv_addr;
	char* address;
	bool started;	
	std::thread acceptorThread;
	//void connectionAcceptor();
	void ClientHandler_(SockClient* tclient, std::thread thisthread);	// Pre-client handler, reads from the buffer
	
	
public:
    bool dolisten;
    int socketfd;
    socklen_t clilen;
    LinkedList<SockClient> clients;
    
    void (*_clientHandler)(CharString* dataIn, CharString* dataOut); // Assigned handler for the client
    
	SocketServer(SocketServerType serverType,
				 char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
				 int port, 
				 int bufferSize, // Packet buffer size
				 void (*clientHandler)(CharString* dataIn, CharString* dataOut)); // dataIn is read-only, for dataOut use dataOut.set(char*)
	
	void start(); // Start the server
	void Close();
};

#endif
