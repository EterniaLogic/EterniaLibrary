#ifndef HTMLSERVER_H_
#define HTMLSERVER_H_

#include "Types/HTTPTypes.h"

// Basic HTML Server, spawned off of the SocketServer with TCP
class HTMLServer {
public:
    HTMLServer(SocketServerType serverType,
                   char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                   int port,
                   int bufferSize,
                   CharString wwwroot);
    
    virtual ~HTMLServer();
};

#endif
