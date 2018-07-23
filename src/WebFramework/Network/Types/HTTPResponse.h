#ifndef HTTPRESPONSE_H_
#define HTTPRESPONSE_H_
#include "HTTPTypes.h"
#include "../../../Data/HashMap.hpp"
#include <iostream>

// The response of an HTML server request
// R/W permissions

class HTTPResponse {
public:
    CharString body, HTTPVer, wwwroot;
    unsigned short responsecode; // '200 OK'
    HashMap<CharString> header;
    
    CharString filestream;
    int streamlen;
    
    HTTPResponse();
    
    
    // get fully constructed HTTP response.
    //  does not include streams (yet)
    CharString toString(int maxpacketsize); 
    
    // Response headers from server (underscores before)
/*    CharString _HTTPver, _Pragma, _Date, _Server, _SetCookie, _CacheControl, _X_UA_Compatible, _Vary, _KeepAlive, _TransferEncoding, 
        ContentType;*/
};


#endif
