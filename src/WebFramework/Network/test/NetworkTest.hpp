#ifndef NETTEST_H_
#define NETTEST_H_

#include "../SocketServer.h"
#include "../ChannelledServer.h"
#include "../HTTPServer.h"
#include "../RESTFulServer.h"
#include <time.h>


CharString localhost = CharString("127.0.0.1\0",9); //9
CharString wwwroot = CharString("./www\0",5);//5


// echo out data, send "TEST!" to the client
void testClientHandler(CharString dataIn, CharString &dataOut, SockClient* client, void* d){
    cout << dataIn << endl;
    dataOut.set("TEST!\r\n",7);
}

void testChannelClientHandler(ChannelledClient *client, PacketChannel* channel){
    CharString packet = channel->recvPacket();
    if(packet.getSize() > 0){
        CharString c = CharString("You said '",10);
        c.concata(packet);
        c.concata(CharString("' on channel ",13));
        c.concata(CharString::ConvertFromInt(channel->getID()));
        c.concata(CharString("\r\n\r\n",4));
        channel->sendPacket(c);
    }else{
        channel->sendPacket(CharString("Empty packet...\r\n",19));
    }
}

void testHTTP(){
    cout << "[Network] testing HTTP Server" << endl;
    
    char* c = new char[5];
    HTTPServer server(localhost, 8080, false, wwwroot);

    server.start(); // async startup
    cout << "[Network] [HTTP Server] Press enter to continue" << endl;
    cin.getline(c,5);
    server.Close();
}

void testGet(HTTPRequest input, HTTPResponse &output){
    output.body = CharString("test GET for ",13);
    output.body.concata(input.URI);
}

void testPost(HTTPRequest input, HTTPResponse &output){
    cout << "POST!" << endl;
}

void testNetwork(){
    char* c = new char[5];
    
    /*cout << "[Network] testing Socket Server" << endl;
    
    // Pure SocketServer
    SocketServer server(SS_TCP,localhost, 9999, 1024, false, testClientHandler);

    server.start(); // async startup
    cout << "[Network] [Socket Server] Press enter to continue to ChannelledServer" << endl;
    cin.getline(c,5);
    server.Close();
    std::this_thread::sleep_for(std::chrono::microseconds(400000));
    
    // Channelled Server
    ChannelledServer server2(SS_TCP,localhost, 9998, 1024, testChannelClientHandler);
    
    server2.start();
    cout << "[Network] [Channelled Server] Press enter to continue." << endl;
    cin.getline(c,5);
    server2.Close();
    std::this_thread::sleep_for(std::chrono::microseconds(400000));*/
    
    
    // RESTFul Server
    // Combined HTML/Restful server
    // server4.setHTMLDir(CharString("./www",4));
    
    RESTFulServer server3(localhost, 9997, wwwroot);
    server3.addEndpoint(new RESTFulEndpoint(HGET, "test/get", testGet));
    server3.addEndpoint(new RESTFulEndpoint(HPOST, "test/post", testPost));
    
    server3.addEndpoint(new RESTFulEndpoint(HGET, "api/company/main", testGet));
    server3.addEndpoint(new RESTFulEndpoint(HGET, "api/company", testGet));
    
    
    server3.start();
    cout << "[Network] [RESTFul Server] Press enter to continue." << endl;
    cin.getline(c,5);
    server3.Close();
}


#endif // NETTEST_H_
