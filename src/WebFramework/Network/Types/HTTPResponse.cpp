#include "HTTPResponse.h"

HTTPResponse::HTTPResponse(){
    responsecode = 400;
    HTTPVer = CharString("HTTP/1.1",8);
    streamlen=0;
}

CharString HTTPResponse::toString(int maxpacketsize){
    // converts the entire response + body to a string.
    string responseX = HTTP::response_codes[responsecode];
    
    CharString data;
    data.concata(HTTPVer);
    data.concata(" \0", 1);
    data.concata(CharString(responseX));
    data.concata("\r\n", 2);
    
    
    // Set MIME
    if(body.getSize() > 0 || filestream.getSize() > 0){
        data.concata("Content-Length: ", 16);
        //cout << "CLEN:: " << body.getSize() << "=" << CharString::ConvertFromInt(body.getSize()).get() << endl;
        if(body.getSize() > 0 || streamlen > 0) 
            data.concata(CharString::ConvertFromLong(body.getSize()+streamlen));
        else data.concata("0",1);
        data.concata("\r\n", 2);
        
        if(filestream.getSize() > 0){
            data.concata("Content-Type: ", 14);
            CharString MIME = CharString("application/octet-stream",24);
            
            for(const auto& n : HTTP::content_type) {
                if(filestream.endsWith(CharString(n.first.c_str(), n.first.length()))){
                    cout << "set mime for filestream to " << n.second << endl;
                    MIME.set(n.second);
                    break;
                }
            }
            
            /*    if(filestream.endsWith(CharString(".jpg",4)) || filestream.endsWith(CharString(".jpeg",5)))
                        MIME.set("image/jpeg",10);
                if(filestream.endsWith(CharString(".htm",4)) || filestream.endsWith(CharString(".html",5)))
                        MIME.set("text/html",9);*/
            data.concata(MIME);
            data.concata("\r\n",2);
            
            
            
            // Ranging bytes (to continue a download or w/e)
            if(streamlen > maxpacketsize){
                //data.concata("Accept-Ranges: bytes\r\n", 21);
            }
        }
    }
    


    
    
    // loop through headers..
    LinkedList<CharString>* headerkeys = header.getKeys();
    headerkeys->freeze();
    //cout << "Response headers = #" << headerkeys->frozenlen << endl;
    for(int i=0;i<headerkeys->frozenlen;i++){
        if(headerkeys->frozen[i] == 0x0) continue;
       // cout << "HEADER == " << headerkeys->frozen[i]->get() << ": " << header.get(*(headerkeys->frozen[i]))->get() << endl;
        data.concata(*headerkeys->frozen[i]);
        data.concata(": ",2);
        data.concata(*header.get(*(headerkeys->frozen[i])));
        data.concata("\r\n",2);
    }
    //data.concata("Content-Type: image/jpeg\r\n",27);
    
    data.concata("\r\n", 2);
    
    // add body!
    if(body.getSize() > 0){
        data.concata(body);
        
        data.concata("\r\n\r\n", 4);
    }
    
    return data;
}
