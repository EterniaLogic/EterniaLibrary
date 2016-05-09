#include "SocketServer.h"

Client::Client(socklen_t address, struct sockaddr_un cli_addr){
	this->alive = true;
	this->address = address;
	this->cli_addr = cli_addr;
}

SocketServer::SocketServer(SocketServerType serverType,
				 int bufferSize,
				 char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
				 int port, 
				 int bufferSize, // Packet buffer size
				 void (*clientHandler)(CharString dataIn, CharString dataOut)){
	this->bufferSize = bufferSize;
	this->port = port; // listen port
	this->address = address; // listen address
	this->_clientHandler = clientHandler; // save the external function for handling the client
	this->stype = serverType;
	
	int newsockfd;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     
     // SOCK_DGRAM, SOCK_STREAM
     
     socketfd = socket(AF_INET, SOCK_STREAM, 0); // << Defines socket type
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
	 
	 
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(port);
     
	 
     
	 
	 
     
     close(newsockfd);
     close(sockfd);
}

// Accept connections while listening
void SocketServer::connectionAcceptor(){
	while(listen){
		listen(sockfd,5);	// Listen for clients
		clilen = sizeof(cli_addr); // get the address
		newsockfd = accept(socketfd, 
					(struct sockaddr *) &cli_addr, 
					&clilen);
		if (newsockfd < 0) 
			error("ERROR on accept");
		
		// Construct the client
		Client *c = new Client();
		
		
		// create a new client thread
		
	}
}


// Start the server
void SocketServer::start(){
	// Bind the port
	if (bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
              std::cout << "Error on binding port " << port << std::endl;
	
	listen=true;
	
	// TCP only request detection
	switch(stype){
		case SS_TCP: // TCP connection listener
				acceptorThread = new std::thread(connectionAcceptor);
			break;
		case SS_UDP: // UDP basic listener
			
			break;
	}
}

// Start the server
void SocketServer::ClientHandler_(Client* tclient, std::thread thisthread){
	// Talk with the client, pre-load into a buffer
	
	
	while(tclient->alive){
		bzero(buffer,this->bufferSize);
		n = read(tclient->sockd, buffer, this->bufferSize-1);
		if (n < 0) error("ERROR reading from socket");
		
		CharString* writeto = new CharString(); // writeto is a string that we write to, used by the
		_clientHandler(new CharString(buffer,this->bufferSize-1), writeto);
		
		n = write(tclient->sockd, writeto->get(), writeto->size());
		if (n < 0) error("ERROR writing to socket");
	}
}

// Close the server
void SocketServer::close(){
	// close the main acceptor (if it is active)
	listen=false;
	acceptorThread.join();
	
	// Stop listening to clients
}