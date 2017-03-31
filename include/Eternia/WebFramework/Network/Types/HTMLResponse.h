#ifndef HMTLRESPONSE_H_
#define HMTLRESPONSE_H_


// The response of an HTML server request
// R/W permissions

class HTMLResponse {
    private:
        CharString *body, *head, *raw;
    public:
        HTMLResponse();

};


#endif
