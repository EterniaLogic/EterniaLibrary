#ifndef NETTEST_H_
#define NETTEST_H_

#include "../SocketServer.h"
#include <time.h>

// echo out data, send "TEST!" to the client
void testClientHandler(CharString* dataIn, CharString* dataOut, void* d){
    cout << dataIn->get() << endl;
    dataOut->set("TEST!",5);
}

void testNetwork(){
    cout << "[Network] testing network server. 127.0.0.1:3001" << endl;

    SocketServer server(SS_TCP, "127.0.0.1", 3001, 256, testClientHandler);

    server.start(); // async startup

    cout << "Press anything to continue" << endl;
    const int readlen = 5;
    char* readt = new char[readlen];
    cin.getline(readt,readlen);

    //server.Close();
}


#endif // NETTEST_H_
