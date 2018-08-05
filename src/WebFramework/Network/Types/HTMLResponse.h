#ifndef HMTLRESPONSE_H_
#define HMTLRESPONSE_H_

#include "../../../Data/includes.h"
#include "HTTPTypes.h"
#include <iostream>

// The response of an HTML server request
// R/W permissions

class HTMLResponse {
    private:
        CharString body, head, raw;
    public:
        HTMLResponse(CharString rawx);

};


#endif
