#include "SocketServer.h"

SocketServer::SocketServer(){
    async=true;
    this->bufferSize = 2048;
    this->stype = SS_TCP;
    this->connected = 0x0;
    this->disconnected = 0x0;
    this->encryptor = 0x0;
    this->decryptor = 0x0;
}

SocketServer::SocketServer(SocketServerType serverType,
                           CharString address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                           int port,
                           int bufferSize, // Packet buffer size
                           bool IPv6,
                           void (*clientHandler)(CharString dataIn, CharString &dataOut, SockClient* client,void* d)) {
    this->bufferSize = bufferSize;
    this->port = port; // listen port
    this->address = address; // listen address
    this->_clientHandler = clientHandler; // save the external function for handling the client
    this->stype = serverType;
    this->async=true;
    this->ipv6=IPv6;
    
    // external function events
    this->connected = 0x0;
    this->disconnected = 0x0;
    this->encryptor = 0x0;
    this->decryptor = 0x0;
}

// Handle basic client stuff
void ClientHandler_(SockClient *tclient, SocketServer *server) {
    // Talk with the client, pre-load into a buffer
    int n;
    const int buflen = server->bufferSize;
    char buffer[buflen];
    CharString writeto;
    
    if(server->connected != 0x0) server->connected(tclient);
    //cout << "Client start! " << tclient << endl;
    
    // prevent blocking
#ifdef LINUXXX
    int x;
    x=fcntl(tclient->sockd, F_GETFL, 0);
    fcntl(tclient->sockd, F_SETFL, x | O_NONBLOCK);
#endif
    
    while(tclient->alive) {
#ifdef LINUXXX
        int error_code;
        int error_code_size = sizeof(error_code);
        int ret = getsockopt(tclient->sockd, SOL_SOCKET, SO_ERROR, &error_code, (socklen_t*)&error_code_size);
        //cout << "socket val = " << error_code << " " << error_code_size << " " << ret << endl;
        
        if(error_code > 0){
            //cout << "Client disconnected!" << endl;
            if(server->disconnected != 0x0) server->disconnected(tclient);
            tclient->alive = false;
            server->clients.remove(tclient);
            return;
        }
        
        n = read(tclient->sockd, buffer, buflen);
        if (n < 0){
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            continue;
        }else if(n==0){
            //cout << "blank packet... (Term connection?)" << endl;   
            if(server->disconnected != 0x0) server->disconnected(tclient);
            tclient->alive = false;
            server->clients.remove(tclient);
            return;
        }
        
        // post-clear extra data in packet... (Prevents extra cpu usage, clearer data stream)
        for(int i=n-1;i<buflen;i++) buffer[i] = 0;

        if(tclient->_clientHandler != 0x0) {
            CharString d = (server->decryptor!=0x0) ? server->decryptor(CharString(buffer,n)) : CharString(buffer,n); // decrypt
            tclient->_clientHandler(d, writeto, tclient, tclient->exVAL);

            if(writeto.getSize() > 0){
                // segment packet if it is too large.
                tclient->sendc(writeto); // encryption in-client
            }
        }
        
#elif defined(WINDOWSXX)
        int iSendResult;

        char recvbuf[server->bufferSize];
        int iResult = recv(tclient->sockd, recvbuf, buflen, 0);
        if (iResult > 0) {
            //printf("Bytes received: %d\n", iResult);

            if(tclient->_clientHandler != 0x0) {
                CharString d = (server->decryptor!=0x0) ? server->decryptor(CharString(recvbuf,n)) : CharString(recvbuf,n); // decrypt
                tclient->_clientHandler(d, writeto, tclient, tclient->exVAL);
                if(writeto.getSize() > 0){
                    tclient->sendc(writeto); // encryption in-client
                }
            }
        }
        else if (iResult == 0) {} // no bytes?
            //printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(tclient->sockd);
            WSACleanup();
            return;
        }
#endif
    }
}


// Accept connections while listening
void SocketServer::tcpConnectionAcceptor() {
    SockClient *c;
    bool gotClient=true;
    cout << "starting TCP listener" << endl;
#ifdef LINUXXX
    listen(socketfd,5); // Listen for clients
#elif defined(WINDOWSXX)
    int iResult = listen(socketfd, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(socketfd);
        WSACleanup();
        return;
    }
#endif

    cout << "Waiting for connections on " << address << ":" <<port << endl;
    while(this->dolisten) {
        // Construct the client
        c = new SockClient();
        c->exVAL = exVAL;
        c->_clientHandler = _clientHandler;
        c->connected = connected;
        c->disconnected = disconnected;
        c->encryptor = encryptor;
        
#ifdef LINUXXX
        clilen = sizeof(c->cli_addr); // get the address size
        c->sockd = accept(socketfd,
                          (struct sockaddr *) &(c->cli_addr),
                          &clilen);
                          
        if(c->sockd == -1){
            std::this_thread::sleep_for(std::chrono::microseconds(10000));
            continue;
        }
        
        char s[INET6_ADDRSTRLEN];
        inet_ntop(AF_INET,
            &(c->cli_addr.sin_addr),
            s, sizeof s);

        //cout << "[Network] Client connected: " << s << endl;
#elif defined(WINDOWSXX)
        // Setup the TCP listening socket
        int iResult = bind( socketfd, result->ai_addr, (int)result->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            printf("bind failed with error: %d\n", WSAGetLastError());
            freeaddrinfo(result);
            closesocket(socketfd);
            WSACleanup();
            return;
        }
        freeaddrinfo(result);
#endif
        
        
        clients.add(c);
        
        //cout << clients.size() << endl;
        
        // create a new client thread
        //if(async){
            c->clientthread = std::thread(&ClientHandler_, c, this);
        //}else{
        //    ClientHandler_(c,this);
        //}
    }
}

// Start the server
void SocketServer::start() {
    int ntype = SOCK_STREAM;
    int proto = 0;
    switch(this->stype) {
        case SS_TCP:
            ntype = SOCK_STREAM;
            break;
        case SS_UDP:
            ntype = SOCK_DGRAM;
            break;
        case SS_ICMP:
            ntype = SOCK_DGRAM;
            proto = IPPROTO_ICMP;
            break;
    }

#ifdef LINUXXX

    // connect socket
    socketfd = socket(ipv6 ? AF_UNSPEC : AF_INET, ntype, proto); // << Defines socket type
    if (socketfd < 0){
        cout << "Error opening socket..." << endl;
        return;
    }

    // allow port to be reusable
    int reusePort = 1;
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEPORT, &reusePort, sizeof(reusePort));

    serv_addr = *(sockaddr_in*)calloc(sizeof(serv_addr),1);
    serv_addr.sin_family = ipv6 ? AF_UNSPEC : AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((short)port);

    // bind port
    if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        std::cout << "Error on binding port " << port << std::endl;
#elif defined(WINDOWSXX)
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = ipv6 ? AF_UNSPEC : AF_INET;
    hints.ai_socktype = ntype;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    //CharString portx = CharString::ConvertFromInt(port);
    char portx[5];
    iResult = getaddrinfo(address.get(), portx, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    // Create a SOCKET for connecting to server
    socketfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socketfd == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return;
    }


    // Setup the TCP listening socket
    iResult = bind( socketfd, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(socketfd);
        WSACleanup();
        return;
    }
    freeaddrinfo(result);
#endif

    dolisten=true;

    // TCP only request detection
    switch(stype) {
        case SS_TCP: // TCP connection listener
            if(async)
                acceptorThread = std::thread(&SocketServer::tcpConnectionAcceptor,this);
            else tcpConnectionAcceptor();
            break;
        case SS_UDP: // UDP basic listener

            break;
        case SS_ICMP: // ICMP basic listener, same as UDP?

            break;
    }
}



// Close the server
void SocketServer::Close() {
    // close the main acceptor (if it is active)

    // close server socket
#ifdef LINUXXX
    close(socketfd);
#elif defined(WINDOWSXX)
    closesocket(socketfd);
    WSACleanup();
#endif

    dolisten=false;
    //if(async) acceptorThread.join();

    // Stop listening to clients
    clients.freeze();
    for(int i=0; i<clients.frozenlen; i++) {
        clients.frozen[i]->alive = false;
#ifdef LINUXXX
        close(clients.frozen[i]->sockd);
        clients.frozen[i]->clientthread.join();
#endif
        //if(async) clients.frozen[i]->clientthread.join();

    }
    clients.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
}
