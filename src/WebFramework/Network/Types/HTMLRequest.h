#ifndef HMTLREQUEST_H_
#define HMTLREQUEST_H_

#include "../../../Data/includes.h"
#include "HTTPTypes.h"
#include <iostream>

// The original HTML Server request
// Read-only permissions

class HTMLRequest {
    private:
        CharString *body, *head, *raw;
    public:
        HTMLRequest(CharString HMTL_raw); // Raw input from the HMTL Server, auto-calculates the header/body

        unordered_map<string,int> getHeader(); // return the header

};


#endif
