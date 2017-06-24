#include "HTTPResponse.h"

HTTPResponse::HTTPResponse(){
    responsecode = 400;
    HTTPVer = CharString("HTTP/1.1",8);
    filestream=0x0;
    streamlen=0;
}

CharString HTTPResponse::toString(){
    // converts the entire response + body to a string.
    string responseX = HTTP::response_codes[responsecode];
    
    CharString data;
    data.concata(HTTPVer);
    data.concata(" \0", 1);
    data.concata(CharString(responseX));
    data.concata("\r\n", 2);
    
    // write content length
    data.concata("Content-Length: ", 16);
    //cout << "CLEN:: " << body.getSize() << "=" << CharString::ConvertFromInt(body.getSize()).get() << endl;
    if(body.getSize() > 0 || streamlen > 0) data.concata(CharString::ConvertFromInt(body.getSize()+streamlen));
    else data.concata("0",1);
    data.concata("\r\n", 2);
    
    // loop through headers..
    LinkedList<CharString> headerkeys = header.getKeys();
    headerkeys.freeze();
    for(int i=0;i<headerkeys.frozenlen;i++){
        if(headerkeys.frozen[i] == 0x0) continue;
        data.concata(*headerkeys.frozen[i]);
        data.concata(": ",2);
        data.concata(*header.get(*(headerkeys.frozen[i])));
        data.concata("\r\n",2);
    }
    
    data.concata("\r\n", 2);
    
    // add body!
    data.concata(body);
    
    data.concata("\r\n\r\n", 4);
    
    return data;
}
