#include "RESTFulServer.h"


// RESTFul http handler
void httphandlerR(HTTPServer* serv, HTTPRequest input, HTTPResponse &output){
    
    // handle and endpoint!
    // if no endpoint handled, continue.
    if(((RESTFulServer*)serv)->handleEndpoint(input,output)) return;
    
    // basic HTTP server...
    if(input.method == HGET){
        output.responsecode = 200; // OK
        serv->handleGET(input, output); // basic handler for files
    }else{
        output.responsecode = 400;
    }
}


RESTFulServer::RESTFulServer(CharString addr, int port, CharString wwwroot){
    this->bufferSize = 32768; // large buffer for sending images, ect.
    this->stype = SS_TCP;
    this->_httphandle = httphandlerR;
    this->exVAL = this;
    this->ipv6=false; // false for now?
    this->wwwroot = wwwroot;
    
    this->port = port; // listen port
    this->address = address; // listen address
}

RESTFulServer* RESTFulServer::addEndpoint(RESTFulEndpoint *endpoint){                      
     switch(endpoint->requestMethod){
        case HGET:
                _get.add(endpoint);
            break;
        case HPOST:
                _post.add(endpoint);
            break;
        case HPUT:
                _put.add(endpoint);
            break;
        case HCONNECT:
                _connect.add(endpoint);
            break;
        case HPATCH:
                _patch.add(endpoint);
            break;
        case HHEAD:
                _head.add(endpoint);
            break;
        case HDELETE:
                _delete.add(endpoint);
            break;
        case HOPTIONS:
                _options.add(endpoint);
            break;
        case HTRACE:
                _trace.add(endpoint);
            break;
     }
     
     return this;
}

bool RESTFulServer::handleEndpoint(HTTPRequest request, HTTPResponse &response){
    switch(request.method){
        case HGET:
                
            break;
        case HPOST:
        
            break;
        case HPUT:
        
            break;
        case HCONNECT:
        
            break;
        case HPATCH:
        
            break;
        case HHEAD:
        
            break;
        case HDELETE:
        
            break;
        case HOPTIONS:
        
            break;
        case HTRACE:
        
            break;
    }
    
    // no endpoint handled.
    return false;
}
