#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_

#include "SocketServer.h"
#include "Types/HTTPRequest.h"
#include "Types/HTTPResponse.h"
#include "../../Parsing/LoadFile.h"


// Basic HTML Server, spawned off of the SocketServer with TCP
class HTTPServer : public SocketServer {
private:
    HashMap<CharString> pagecache;
    
    
public:
    void (*_httphandle)(HTTPServer* server, HTTPRequest input, HTTPResponse &output); // handle a request
    CharString wwwroot; // site folder "./www", "/var/www"
    
    HTTPServer();
    HTTPServer(CharString address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                   int port,
                   bool ipv6,
                   CharString wwwroot);
    virtual ~HTTPServer();
    
    
    // undefined
    void clearCache();
    void useCahce(bool v); // use data cache to increase speed?
    
    
    // internal handle, BASIC html (overwrite _httphandle to use your own.
    void handleGET(HTTPRequest input, HTTPResponse &output);
};

#endif
