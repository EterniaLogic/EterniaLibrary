#include "HTTPRequest.h"

HTTPRequest::HTTPRequest(CharString inputData){
    ContentLength=0;
    method = HNONE; // unknown HTTP method...
    
    parse(inputData);
}

bool HTTPRequest::deconstructFirst(CharString data){
     LinkedList<CharString> heads = data.split(' ','\0');
     
     if(heads.size() == 3){
         heads.freeze();
         
         for(const auto& n : HTTP::method_map) {
            if(heads.frozen[0].startsWith(n.first)){
                method = n.second;
                break;
            }
        }
        
        // error for decoding
        if(method == HNONE){
            cout << "HTTPRequest Error decoding request method..." << endl;
            return false; 
        }
        
        
        // URI
        URI = heads[1];
        
        // HTTP Version
        HTTPVer = heads[2];
        
        cout << "HTTP Request: '" << heads[0] << " " << heads[1] << " " << heads[2] << "'" << endl;
        return true;
        
    }else{
        // incorrect head size!
        cout << "Bad Request Line: " << data << endl;
        return false;
    }
}


// deconstruct input.
bool HTTPRequest::parse(CharString data){
    LinkedList<CharString> headBody = data.split(CharString("\r\n\r\n",4));
    LinkedList<CharString> heads = (headBody.get(0).split(CharString("\r\n",2)));
    bool error=false;
    
    
    if(heads.size() > 0){
        // deconstruct first line of HTTP request.
        if(deconstructFirst(heads[0])){
            // now to do normal request header values... Content-Type, ect.
            for(int i=1;i<heads.size();i++){
                LinkedList<CharString> heads2 = heads[i].split(CharString(": ",2));
                CharString headName = heads2.get(0);
                
                // data for each line
                CharString headData = heads2.get(1);
                for(int i=2;i<heads2.size();i++){
                    headData.concata(heads2.get(i));
                }
                
                // add to hashmap
                header.add(headName, headData);
            }
        }else error=true;
    }else error=true;
    
    // convert data to body
    body = headBody.get(1);
    for(int i=2;i<headBody.size();i++){
        body.concata("\r\n\r\n",4);
        body.concata(headBody.get(i));
    }
    
    return error;
}
