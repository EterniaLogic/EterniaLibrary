#include "SocketServer.h"

SocketServer::SocketServer(){

}

SocketServer::SocketServer(SocketServerType serverType,
                           char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                           int port,
                           int bufferSize, // Packet buffer size
                           void (*clientHandler)(CharString* dataIn, CharString* dataOut)) {
    this->bufferSize = bufferSize;
    this->port = port; // listen port
    this->address = address; // listen address
    this->_clientHandler = clientHandler; // save the external function for handling the client
    this->stype = serverType;

#if __linux__ || __unix__
    // SOCK_DGRAM, SOCK_STREAM
    int stype = SOCK_STREAM;
    int proto = 0;
    switch(stype) {
        case SS_TCP:
            stype = SOCK_STREAM;
            break;
        case SS_UDP:
            stype = SOCK_DGRAM;
            break;
        case SS_ICMP:
            stype = SOCK_DGRAM;
            proto = IPPROTO_ICMP;
            break;
    }

    socketfd = socket(AF_INET, stype, proto); // << Defines socket type
    if (socketfd < 0)
        error("ERROR opening socket for server");
    bzero((char *) &serv_addr, sizeof(serv_addr));


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
#endif
}

// Handle basic client stuff
void ClientHandler_(SockClient* tclient) {
    // Talk with the client, pre-load into a buffer
    int n;
    char buffer[BUFFER_SIZEX];

    while(tclient->alive) {
#if __linux__ || __unix__


        n = read(tclient->sockd, buffer, BUFFER_SIZEX);
        if (n < 0) error("ERROR reading from socket");

        CharString* writeto = new CharString(); // writeto is a string that we write to, used by the

        if(tclient->_clientHandler != 0x0) {
            tclient->_clientHandler(new CharString(buffer,BUFFER_SIZEX), writeto);

            n = write(tclient->sockd, writeto->get(), writeto->getSize());
            if (n < 0) error("ERROR writing to socket");
        }
#endif // __linux__
    }
}


// Accept connections while listening
void SocketServer::tcpConnectionAcceptor() {
    while(dolisten) {
#if __linux__ || __unix__
        listen(socketfd,5); // Listen for clients
#endif

        // Construct the client
        SockClient *c = new SockClient();
#if __linux__ || __unix__
        clilen = sizeof(c->cli_addr); // get the address
        c->sockd = accept(socketfd,
                          (struct sockaddr *) &(c->cli_addr),
                          &clilen);
#endif
        if (c->sockd < 0)
            error("ERROR on accepting client");

        clients.add(c);
        c->_clientHandler = _clientHandler;

        // create a new client thread
        // TODO: Commented out, but REQUIRED
        //c->clientthread = std::thread(&ClientHandler_, c);
    }
}


// Start the server
void SocketServer::start() {
    // Bind the port
#if __linux__ || __unix__
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        std::cout << "Error on binding port " << port << std::endl;
#endif
    dolisten=true;

    // TCP only request detection
    switch(stype) {
        case SS_TCP: // TCP connection listener
            acceptorThread = std::thread(&SocketServer::tcpConnectionAcceptor,this);
            break;
        case SS_UDP: // UDP basic listener

            break;
        case SS_ICMP: // ICMP basic listener

            break;
    }
}



// Close the server
void SocketServer::Close() {
    // close the main acceptor (if it is active)
    //close(newsockfd);

    dolisten=false;
    acceptorThread.join();

    // Stop listening to clients
    clients.freeze();
    for(int i=0; i<clients.frozenlen; i++) {
        clients.frozen[i]->alive = false;
        clients.frozen[i]->clientthread.join();
        close(clients.frozen[i]->sockd);
    }
    clients.clear();


    // close server socket
    close(socketfd);
}
