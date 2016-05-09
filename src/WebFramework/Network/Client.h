#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
 
 
class Client{
public:
	Client();
	
	int sockd;
	socklen_t address;
	struct sockaddr_un  cli_addr;
	bool alive;
};

#endif