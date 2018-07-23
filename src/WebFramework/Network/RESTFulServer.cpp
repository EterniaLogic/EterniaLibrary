#include "RESTFulServer.h"


// RESTFul http handler
void httphandlerR(HTTPServer* serv, HTTPRequest input, HTTPResponse &output){
    cout << "restful http handler" << endl;
    // handle and endpoint!
    // if no endpoint handled, continue.
    if(((RESTFulServer*)serv)->handleEndpoint(input,output)){
        output.responsecode = 200;
        return;
    }else if(input.method == HGET){ // Standard HTTP!
        output.responsecode = 200; // OK
        //cout << "standard http GET" << endl;
        serv->handleGET(input, output); // basic handler for files
        //cout << "standard http GET end " << output.body.getSize() << endl;
    }else{ // bad request
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
    this->address = addr; // listen address
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

bool runendpoint(LinkedList<RESTFulEndpoint> list, HTTPRequest request, HTTPResponse &response){
    list.freeze();
    for(int i=0;i<list.frozenlen;i++){
        RESTFulEndpoint *e = list.frozen[i];
        if(e != 0x0){
            if(e->checkURI(request)){
                cout << e->uri.get() << endl;
                e->handle(request, response);
                return true;
            }
        }
    }
    return false;
}

bool RESTFulServer::handleEndpoint(HTTPRequest request, HTTPResponse &response){
    //cout << "handleEndpoint " << request.method << endl;
    switch(request.method){
        case HGET:
                return runendpoint(_get, request, response);
            break;
        case HPOST:
                return runendpoint(_post, request, response);
            break;
        case HPUT:
                return runendpoint(_put, request, response);
            break;
        case HCONNECT:
                return runendpoint(_connect, request, response);
            break;
        case HPATCH:
                return runendpoint(_patch, request, response);
            break;
        case HHEAD:
                return runendpoint(_head, request, response);
            break;
        case HDELETE:
                return runendpoint(_delete, request, response);
            break;
        case HOPTIONS:
                return runendpoint(_options, request, response);
            break;
        case HTRACE:
                return runendpoint(_trace, request, response);
            break;
    }
    
    // no endpoint handled.
    return false;
}
