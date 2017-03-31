#ifndef HMTLREQUEST_H_
#define HMTLREQUEST_H_


// The original HTML Server request
// Read-only permissions

class HTMLResponse {
    private:
        CharString *body, *head, *raw;
    public:
        HTMLRequest(CharString* HMTL_raw); // Raw input from the HMTL Server, auto-calculates the header/body

        unordered_map<string,int> getHeader(); // return the header

};


#endif
