#ifndef SCLIENT_H_
#define SCLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Linux
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#elif __linux__ || __unix__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#elif __APPLE__

#endif




#include <thread>
#include "../../Data/CharString.h"
using namespace std;

#if __linux__ || __unix__
struct sockaddr_un {
    sa_family_t sun_family;               /* AF_UNIX */
    char        sun_path[108];            /* pathname */
};
#endif

class SockClient {
    public:
        SockClient();

        int sockd;
#ifdef __linux__ || __unix__
        socklen_t address;
        sockaddr_in cli_addr;
#endif
        bool alive;
        std::thread clientthread;

        void (*_clientHandler)(CharString* dataIn, CharString* dataOut);
};

#endif
