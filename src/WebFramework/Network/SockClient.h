#ifndef SCLIENT_H_
#define SCLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
#elifdef __APPLE__

#endif




#include <thread>
#include "../../Data/CharString.h"
using namespace std;

typedef unsigned int sa_family_t;

#if __linux__ || __unix__
struct sockaddr_un {
    sa_family_t sun_family;               /* AF_UNIX */
    char        sun_path[108];            /* pathname */
};
#endif

class SockClient {
    public:
        SockClient();
        void* exVAL;
#ifdef LINUXXX
        int sockd;
        socklen_t address;
        sockaddr_in cli_addr;
#elif defined(WINDOWSXX)
        SOCKET ClientSocket;
#endif
        bool alive;
        std::thread clientthread;

        void (*_clientHandler)(CharString* dataIn, CharString* dataOut, void* d);
};

#endif
