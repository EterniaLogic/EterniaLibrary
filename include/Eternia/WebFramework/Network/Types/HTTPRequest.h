#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_
#include "HTTPTypes.h"
#include "../../../Data/HashMap.hpp"

// Converts a raw HTTP

class HTTPRequest {
private:
    bool deconstructFirst(CharString data);
public:
    CharString body, wwwroot;
    HTTPMETHOD method; // GET, PUT, POST, ect.
    CharString URI, HTTPVer;
    unsigned int ContentLength;
    HashMap<CharString> header;
    
    HTTPRequest(CharString data);
    
    // parse HTTP request string into class
    bool parse(CharString data);
    
    // Header Values
    /*CharString URI, HTTPVer, Host, ConnectionType, Pragma, CacheControl, 
        UserAgent, Accept, Referer, AcceptEncoding, AcceptLanguage, Cookie;*/
    
    // Combine all HTTP Request data into a string.
    CharString toString();
};


#endif
