#include "HTTPServer.h"

// handle all data transactions here.
void chandler(CharString dataIn, CharString &dataOut, SockClient* client, void* instance){
    HTTPServer *serv = (HTTPServer*)instance;
    cout << "Request size: " << dataIn.getSize() << endl;
    HTTPRequest req = HTTPRequest(dataIn);
    req.wwwroot = serv->wwwroot;
    HTTPResponse resp;
    resp.wwwroot = serv->wwwroot;
    
    if(serv->_httphandle != 0x0)
        serv->_httphandle(serv, req, resp);
    
    cout << "Response: " << resp.toString().get() << endl;
    if(resp.filestream.getSize() > 0){
        // chunk out data
        client->sendc(resp.toString());
        ifstream file;
        file.open(resp.filestream.get(), ifstream::binary);
        
        if(resp.streamlen > serv->bufferSize){
            char* buffer = (char*)malloc(serv->bufferSize);
            int esize = ceil(((float)resp.streamlen) / ((float)serv->bufferSize));
            int tsize = resp.streamlen-esize*serv->bufferSize; // last value size
            
            for(int i=0;i<esize;i++){
                //cout << "ha " << i << endl;
                if(i >= esize-1){
                    cout << "end" << endl;
                    memset(buffer,0,serv->bufferSize);
                    file.read(buffer,tsize);
                    client->sendc(CharString(buffer, tsize));
                    cout << "end2" << endl;
                }else{
                    file.read(buffer,serv->bufferSize);
                    client->sendc(CharString(buffer, serv->bufferSize));
                }
            }
        }
    }else
        dataOut = resp.toString();
}

bool fileExists(CharString loc){
    ifstream file;
    file.open(loc.get(), ifstream::binary);
    return file.good();
}

int fileSize(CharString loc){
    ifstream file;
    file.open(loc.get(), ifstream::binary);
    
    file.seekg (0, file.end);
    int length = file.tellg();
    file.close();
    
    return length;
}

ifstream* getFileStream(CharString loc){
    ifstream file;
    file.open(loc.get(), ifstream::binary);
    
    return &file;
}

// directly retrieve a file
CharString retrieveFile(CharString loc){
    char* buffer;
    ifstream file;
    file.open(loc.get(), ifstream::binary);
    
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    buffer = (char*)malloc(length);
    
    file.read(buffer,length);
    
    file.close();
    
    return CharString(buffer,length);
}

// handle HTTP requests. Overrideable for RESTFul. (RESTFul server also implements basic wwwroot, but has overriding)
// Basic HTTP GET-only requests
void httphandler(HTTPServer* serv, HTTPRequest input, HTTPResponse &output){
    if(input.method == HGET){
        output.responsecode = 200; // OK (default, unless no file retrieved)
        
        serv->handleGET(input, output);
    }else{
        // return a 400 Bad Request error
        output.responsecode=400;
    }
}


HTTPServer::HTTPServer(char* address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                   int port,
                   bool IPv6,
                   CharString wwwroot){
    this->bufferSize = 32768; // large buffer for sending images, ect.
    this->stype = SS_TCP;
    this->_clientHandler = chandler; // save the external function for handling the client
    this->_httphandle = httphandler;
    this->exVAL = this;
    this->ipv6=IPv6;
    this->wwwroot = wwwroot;
    
    this->port = port; // listen port
    this->address = address; // listen address
}

HTTPServer::HTTPServer(){
    this->bufferSize = 32768; // large buffer for sending images, ect.
    this->stype = SS_TCP;
    this->_clientHandler = chandler; // save the external function for handling the client
    this->_httphandle = httphandler;
    this->exVAL = this;
    this->ipv6=false;
}

HTTPServer::~HTTPServer(){}

void HTTPServer::handleGET(HTTPRequest input, HTTPResponse &output){
    // retrieve file!
    if(input.URI == CharString("/",1)){
        CharString l = output.wwwroot.clone();
        l.concata("/index.html", 11);
        
        if(fileExists(l)){
            output.body = retrieveFile(l);
            output.header.add(CharString("Content-Type",12), new CharString("text/html",9));
        }else{
            output.responsecode = 404;
        }
    }else{
        input.URI.concatb(output.wwwroot);
        
        if(fileExists(input.URI)){
            // auto-figure out MIME type...
            CharString* MIME = new CharString("application/octet-stream",24);
            
            for(const auto& n : HTTP::content_type) {
                if(input.URI.endsWith(CharString(n.first.c_str(), n.first.length()))){
                    *MIME = n.second;
                    break;
                }
            }
        
            output.header.add(CharString("Content-Type",12), MIME);
            
            if(fileSize(input.URI) > bufferSize){
                output.filestream = input.URI;
                
                //output.filestream = getFileStream(input.URI);
                output.streamlen = fileSize(input.URI);
            }else output.body = retrieveFile(input.URI); // set file data.
        }else{
            output.responsecode = 404;
        }
    }
}

