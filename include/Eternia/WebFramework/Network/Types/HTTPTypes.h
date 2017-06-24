#ifndef HTTPTYPES_H_
#define HTTPTYPES_H_

#include <unordered_map>
#include <string>
#include "../../../Data/CharString.h"

enum HTTPMETHOD {HNONE, HGET, HPOST, HDELETE, HCONNECT, HPUT, HPATCH, HHEAD, HOPTIONS, HTRACE};

namespace HTTP{
    extern unordered_map<string, HTTPMETHOD> method_map;
    extern unordered_map<int, string> response_codes;
    extern unordered_map<string, string> content_type;
}
#endif
