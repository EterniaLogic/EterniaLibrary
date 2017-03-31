#define URL_END_H_
#ifndef URL_END_H_

#include "../../Data/CharString.h"

class UrlEncoding {
    public:
        UrlEncoding();

        static CharString decodeUrl(CharString url);
        static CharString encodeUrl(CharString url);
};

#endif
