#ifndef BACKEND_H_
#define BACKEND_H_
#include "../Network/network.h"

// common class for backends to work with polymorphism

class Backend{
public:
    SocketServer* server;
    Backend(){server=0x0;}
    
    void start();
    void clienthandle();
    void listener();
};

#endif
