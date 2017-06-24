#ifndef NETTEST_H_
#define NETTEST_H_

#include "../SocketServer.h"
#include "../ChannelledServer.h"
#include "../HTTPServer.h"
#include <time.h>

// echo out data, send "TEST!" to the client
void testClientHandler(CharString dataIn, CharString &dataOut, SockClient* client, void* d){
    cout << dataIn.get() << endl;
    dataOut.set("TEST!",5);
}

void testChannelClientHandler(ChannelledClient *client, PacketChannel* channel){
    
}

void testHTTP(){
    cout << "[Network] testing HTTP Server" << endl;
    
    char* c = new char[5];
    HTTPServer server("0.0.0.0", 8080, false, CharString("./www",5));

    server.start(); // async startup
    cout << "[Network] [HTTP Server] Press enter to continue" << endl;
    cin.getline(c,5);
    server.Close();
}

void testNetwork(){
    cout << "[Network] testing Socket Server" << endl;
    char* c = new char[5];
    // Pure SocketServer
    SocketServer server(SS_TCP,"0.0.0.0", 9999, 1024, false, testClientHandler);

    server.start(); // async startup
    cout << "[Network] [Socket Server] Press enter to continue to ChannelledServer" << endl;
    cin.getline(c,5);
    server.Close();
    
    // Channelled Server
    ChannelledServer server2(SS_TCP,"0.0.0.0", 9999, 1024, testChannelClientHandler);
    
    server2.start();
    cout << "[Network] [Channelled Server] Press enter to continue." << endl;
    cin.getline(c,5);
    server2.Close();
    
    // HTML Server
    // server3.setHTMLDir("htdocs"); // HTML directory
    
    // RESTFul Server
    // Combined HTML/Restful server
    // server4.setHTMLDir("htdocs");
    // server4.addEndpoint(R_GET, "test/get", testGet);
    // server4.addEndpoint(R_POST, "test/post", testPost);
}


#endif // NETTEST_H_
