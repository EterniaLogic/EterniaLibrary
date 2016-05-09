#ifndef RESTFULSERVER_H_
#define RESTFULSERVER_H_

#include "HTMLServer.h"

// RESTFul Server
// Allows for endpoints and JSON encoding

class RESTFulServer{
private:
	unordered_list<string,string>* endpoints;
	
public:
	RESTFulServer(int port);
	
	RESTFulServer* newEndpoint(CharString* url, 
							   HTMLMETHOD requestMethod, 
								void (*returnfunc)(HTMLRequest* request, HTMLResponse* response)); // e.g.: &index, where "void index(HTMLRequest* request, HTMLResponse* response)"
	
	void request(); // HTML Request fron a client
	
	void start(); // Start the RESTFul server
};

#endif