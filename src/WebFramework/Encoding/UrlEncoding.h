#define URL_END_H_
#ifndef URL_END_H_

#include "../../Data/CharString.h"

// URL encoding replaces special characters and spaces with %20, etc.

class UrlEncoding {
    public:
        UrlEncoding();

        static CharString decodeUrl(CharString url);
        static CharString encodeUrl(CharString url);
};

#endif
