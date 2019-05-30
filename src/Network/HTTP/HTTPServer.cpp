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
    
    if(serv->_httphandle == 0x0)
        cout << "no http handler..." << endl;
    
    //cout << "file? " << resp.filestream.get() << " " << resp.streamlen << endl;
    //cout << "body? " << resp.body.getSize() << endl;
    
    //cout << "Response: " << resp.toString(serv->bufferSize).get() << "\n\n" << endl;
    CharString respx = resp.toString(serv->bufferSize);
    cout << "Response code "<< resp.responsecode <<" size " << respx.getSize() << " filename: " << resp.filestream << endl;
    //cout << respx << endl;
    //client->sendc(resp.toString(serv->bufferSize));
    
    
    if(resp.filestream.getSize() > 2){
        // chunk out data
        
        //resp.header.add(CharString("Transfer-Encoding",17),new CharString("identity",8));
        //resp.header.add(CharString("Content-Encoding",17),new CharString("identity",8));
        
        char* buffer = (char*)malloc(serv->bufferSize);
        client->sendc(respx);
        ifstream file;
        file.open(resp.filestream.get(), ifstream::binary);
        file.seekg(0);
        
        if(resp.streamlen > serv->bufferSize){
            /*HTTPResponse respT;
            respT.responsecode = 206;
            CharString* bytesc = new CharString("bytes=0-4048",12);
            CharString* blength = new CharString("4048",4);
            respT.header.add(CharString("Content-Type",12), new CharString("image/jpeg",10));
            respT.header.add(CharString("Content-Range",13), bytesc);
            respT.header.add(CharString("Content-Length",14), blength);
            //respT.header.add(CharString("Accept-Ranges",13), new CharString("bytes",5));
            //respT.streamlen = resp.streamlen;
            
            bytesc->set("bytes 0-4048/*",14);
            int bytesperpacket = serv->bufferSize - respT.toString(serv->bufferSize).getSize();
            //cout << "TEST PACKET: " << respT.toString(serv->bufferSize).get() << endl;
            //cout << "available content length = " << bytesperpacket << endl;*/
            
            
            int count=0;
            
            /*int size=serv->bufferSize;
            for(uint64_t count=0;count<resp.streamlen;){
                size = serv->bufferSize;
                if(size+count > resp.streamlen)
                    size = resp.streamlen - count;
                CharString t = CharString("bytes ",6);
                t.concata(CharString::ConvertFromLong(count));
                t.concata(CharString("-",1));
                t.concata(CharString::ConvertFromLong(count+size));
                t.concata(CharString("/",1));
                t.concata(CharString::ConvertFromLong(size));
                bytesc->set(t);
                CharString s = respT.toString(serv->bufferSize);
                //client->sendc(s);
                
                size = size-s.getSize();
                
                memset(buffer,0,size);
                file.read(buffer,size);
                respT.body = CharString(buffer,size);
                blength->set(CharString::ConvertFromLong(size));
                
                // redo size
                t = CharString("bytes ",6);
                t.concata(CharString::ConvertFromLong(count+1));
                t.concata(CharString("-",1));
                t.concata(CharString::ConvertFromLong(count+1+size));
                t.concata(CharString("/",1));
                t.concata(CharString::ConvertFromLong(size));
                bytesc->set(t);
                blength->set(CharString::ConvertFromLong(size));
                
                s = respT.toString(serv->bufferSize);
                client->sendc(s);
                count += size+1;
                std::this_thread::sleep_for(std::chrono::microseconds(250));
            }*/
            
            
            int size = serv->bufferSize-18;
            for(int count=0;count<resp.streamlen;){
                size = serv->bufferSize-18;
                if(count+size >= resp.streamlen){
                    cout << "end" << endl;
                    size = resp.streamlen-count;
                }
                memset(buffer,0,serv->bufferSize);
                file.read(buffer,size);
                
                cout << size << "  Left: "<< resp.streamlen-count-size << endl;
                
                CharString data = CharString(buffer,size);
                
                client->sendc(data);
                
                count += size;
                std::this_thread::sleep_for(std::chrono::microseconds(1000));
            }
            client->sendc(CharString("\r\n",2));
        }
    }else
        dataOut = respx;
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
    cout << "standard http handler" << endl;
    if(input.method == HGET){
        output.responsecode = 200; // OK (default, unless no file retrieved)
        
        serv->handleGET(input, output);
    }else{
        // return a 400 Bad Request error
        output.responsecode=400;
    }
}


HTTPServer::HTTPServer(CharString address, // address: (i.e  0.0.0.0, 127.0.0.1, eternialogic.com)
                   int port,
                   bool IPv6,
                   CharString wwwroot){
    this->bufferSize = 128000; // large buffer for sending images, ect.
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
    this->bufferSize = 128000; // large buffer for sending images, ect.
    this->stype = SS_TCP;
    this->_clientHandler = chandler; // save the external function for handling the client
    this->_httphandle = httphandler;
    this->exVAL = this;
    this->ipv6=false;
}

HTTPServer::~HTTPServer(){}

void HTTPServer::handleGET(HTTPRequest input, HTTPResponse &output){
    // retrieve file!
    CharString uri = input.URI;
    cout << "handleGET => " << uri << endl;
    
    if(uri.compare(CharString("/"))){
        //cout << "handleGET index" << endl;
        CharString l = output.wwwroot.clone();
        l.concata("/index.html", 11);
        //cout << "rfile" << endl;
        
        if(fileExists(l)){
            cout << "fopen " << l << endl;
            output.body = retrieveFile(l);
            //cout << "fbody: " << output.body.get() << endl;
            //cout << "fheaderset" << endl;
            output.header.add(CharString("Content-Type",12), CharString("text/html",9));
            //cout << "fheader" << endl;
            output.responsecode = 200;
        }else{
            output.responsecode = 404;
        }
    }else{
        //input.URI.concatb(output.wwwroot);
        CharString s = CharString("\0",0);
        s.concata(output.wwwroot);
        s.concata(uri);
        
        if(fileExists(s)){
            //cout << "URIx: " << output.wwwroot.get() << " " << s.get() << endl;
            
           
            
            if(fileSize(s) > bufferSize){
                output.filestream = s;
                
                //output.filestream = getFileStream(input.URI);
                output.streamlen = fileSize(s);
            }else output.body = retrieveFile(s); // set file data.
            output.responsecode = 200;
        }else{
            output.responsecode = 404;
        }
    }
}

