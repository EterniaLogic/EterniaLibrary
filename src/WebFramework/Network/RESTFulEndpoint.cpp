#include "RESTFulServer.h"
 
RESTFulEndpoint::RESTFulEndpoint(HTTPMETHOD requestmethod, // HPOST/HGET/HPUT, ect.
                    CharString uri, // "Overriding URI location /index/data/1/1"
                    void (*returnfuncx)(HTTPRequest request, HTTPResponse &response)){
    this->uri = uri;
    this->returnfunc = returnfuncx;
    this->requestMethod = requestmethod;
}

bool RESTFulEndpoint::checkURI(HTTPRequest request){
    CharString urit = CharString("/",1);
    urit.concata(uri);
    
    cout << request.URI.get() << " starts with /" << uri << "? " << request.URI.startsWith(urit) << endl;
    if(request.URI.startsWith(urit))
        return true;
    
    return false;
}

bool RESTFulEndpoint::handle(HTTPRequest request, HTTPResponse &response){
    //cout << "pre-handle endpoint " << uri.get() << endl;
    
    returnfunc(request, response);
}
