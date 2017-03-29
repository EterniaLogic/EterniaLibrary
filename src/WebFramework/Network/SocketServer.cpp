#include "SocketServer.h"

SocketServer::SocketServer(){

}

SocketServer::SocketServer(SocketServerType serverType,
                           char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                           int port,
                           int bufferSize, // Packet buffer size
                           void (*clientHandler)(CharString* dataIn, CharString* dataOut,void* d)) {
    this->bufferSize = bufferSize;
    this->port = port; // listen port
    this->address = address; // listen address
    this->_clientHandler = clientHandler; // save the external function for handling the client
    this->stype = serverType;

#ifdef LINUXXX
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
    serv_addr = *(sockaddr_in*)calloc(sizeof(sockaddr_in),1);//bzero((char *) &serv_addr, sizeof(serv_addr));


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
#elif defined(WINDOWSXX)
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    //CharString portx = CharString::ConvertFromInt(port);
    char portx[5];
    sprintf(portx,"%d",port);
    iResult = getaddrinfo(address, portx, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }
#endif
}

// Handle basic client stuff
void ClientHandler_(SockClient* tclient) {
    // Talk with the client, pre-load into a buffer
    int n;
    char buffer[BUFFER_SIZEX];
    CharString* writeto = new CharString();
    while(tclient->alive) {
#if defined(__linux__) || defined(__unix__)
        n = read(tclient->sockd, buffer, BUFFER_SIZEX);
        if (n < 0) error("ERROR reading from socket");

        CharString* writeto = new CharString(); // writeto is a string that we write to, used by the

        if(tclient->_clientHandler != 0x0) {
            tclient->_clientHandler(new CharString(buffer,BUFFER_SIZEX), writeto);

            n = write(tclient->sockd, writeto->get(), writeto->getSize());
            if (n < 0) error("ERROR writing to socket");
        }
#elif defined(WINDOWSXX)
        int iSendResult;
        char recvbuf[256];
        int recvbuflen = 256;
        int iResult = recv(tclient->ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            //printf("Bytes received: %d\n", iResult);

            if(tclient->_clientHandler != 0x0) {
                tclient->_clientHandler(new CharString(recvbuf,recvbuflen), writeto, tclient->exVAL);
                iSendResult = send(tclient->ClientSocket, writeto->get(), writeto->getSize(), 0);
                if (iSendResult == SOCKET_ERROR) {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    closesocket(tclient->ClientSocket);
                    WSACleanup();
                    return;
                }
            }
        }
        else if (iResult == 0) {} // no bytes?
            //printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(tclient->ClientSocket);
            WSACleanup();
            return;
        }
#endif
    }
}


// Accept connections while listening
void SocketServer::tcpConnectionAcceptor() {
    while(dolisten) {
#ifdef LINUXXX
        listen(socketfd,5); // Listen for clients
#elif defined(WINDOWSXX)
        int iResult = listen(ListenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR) {
            printf("listen failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return;
        }
#endif

        // Construct the client
        SockClient *c = new SockClient();
#ifdef LINUXXX
        clilen = sizeof(c->cli_addr); // get the address
        c->sockd = accept(socketfd,
                          (struct sockaddr *) &(c->cli_addr),
                          &clilen);

        if (c->sockd < 0)
            error("ERROR on accepting client");
#elif defined(WINDOWSXX)
        c->ClientSocket = accept(ListenSocket, NULL, NULL);
        if (c->ClientSocket == INVALID_SOCKET) {
            printf("accept failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return;
        }
#endif
        clients.add(c);
        c->_clientHandler = _clientHandler;

        // create a new client thread
        // TODO: Commented out, but REQUIRED
        c->clientthread = std::thread(&ClientHandler_, c);
    }
}


// Start the server
void SocketServer::start() {
    // Bind the port
#ifdef LINUXXX
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        std::cout << "Error on binding port " << port << std::endl;
#elif defined(WINDOWSXX)
    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return;
    }


    // Setup the TCP listening socket
    int iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }
    cout << "Port bound... " << result->ai_addr << endl;
    freeaddrinfo(result);
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
#ifdef LINUXXX
        close(clients.frozen[i]->sockd);
#endif
    }
    clients.clear();

    // close server socket
#ifdef LINUXXX
    close(socketfd);
#elif defined(WINDOWSXX)
    closesocket(ListenSocket);
    WSACleanup();
#endif
}
