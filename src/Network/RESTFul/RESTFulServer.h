#ifndef RESTFULSERVER_H_
#define RESTFULSERVER_H_

#include "../HTTP/HTTPServer.h"

// RESTFul Server
// Allows for endpoints and JSON encoding

// Endpoint
class RESTFulEndpoint{
private:
    void (*returnfunc)(HTTPRequest request, HTTPResponse &response);
public:
    CharString uri;
    HTTPMETHOD requestMethod;
    
    
    RESTFulEndpoint(HTTPMETHOD requestmethod, // HPOST/HGET/HPUT, ect.
                    CharString uri, // "Overriding URI location /index/data/1/1"
                    void (*returnfuncx)(HTTPRequest request, HTTPResponse &response));
    
    bool checkURI(HTTPRequest request); // URI along the path?
    bool handle(HTTPRequest request, HTTPResponse &response);
};

// Server
class RESTFulServer : public HTTPServer {
    private:
        LinkedList<RESTFulEndpoint*> _get, _trace, _post, _put, _delete, _options, _head, _patch, _connect;

    public:
        RESTFulServer(CharString addr, int port, CharString wwwroot);

        RESTFulServer* addEndpoint(RESTFulEndpoint *endpoint); 

        // used during request.
        bool handleEndpoint(HTTPRequest request, HTTPResponse &response);
        
};

#endif
