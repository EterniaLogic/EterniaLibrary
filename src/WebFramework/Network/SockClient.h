#ifndef SCLIENT_H_
#define SCLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <thread>
#include "../../Data/CharString.h"
using namespace std;

struct sockaddr_un {
   sa_family_t sun_family;               /* AF_UNIX */
   char        sun_path[108];            /* pathname */
};

class SockClient{
public:
	SockClient();
	
	int sockd;
	socklen_t address;
	sockaddr_in cli_addr;
	bool alive;
	std::thread clientthread;
	
	void (*_clientHandler)(CharString* dataIn, CharString* dataOut);
};

#endif
