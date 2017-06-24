#include "HTTPTypes.h"

namespace HTTP{
    unordered_map<string, HTTPMETHOD> method_map = {
        {"GET", HGET},
        {"POST", HPOST},
        {"DELETE", HDELETE},
        {"CONNECT", HCONNECT},
        {"PUT", HPUT},
        {"PATCH", HPATCH},
        {"HEAD", HHEAD},
        {"OPTIONS", HOPTIONS},
        {"TRACE", HTRACE}
    };


    unordered_map<int, string> response_codes = {
        {100, "100 Continue\0"},
        {101, "101 Switching Protocols\0"},
        {102, "102 Processing\0"}, // WebDAV
        
        // Success
        {200, "200 OK\0"},
        {201, "201 Created\0"},
        {202, "202 Accepted\0"},
        {203, "203 Non-Authoritative Information\0"}, // Proxy
        {204, "204 No Content\0"},
        {205, "205 Reset Content\0"},
        {206, "206 Partial Content\0"},
        {207, "207 Multi-Status\0"}, // WebDAV
        {208, "208 Already Reported\0"}, // WebDAV
        {226, "226 IM Used\0"},
        
        // Redirection
        {300, "300 Multiple Choices\0"},
        {301, "301 Moved Permanently\0"},
        {302, "302 Found\0"},
        {303, "303 See Other\0"},
        {304, "304 Not Modified\0"},
        {305, "305 Use Proxy\0"},
        {306, "306 Switch Proxy\0"},
        {307, "307 Temporary Redirect\0"},
        {308, "308 Permanent Redirect\0"},
        
        // Client Errors
        {400, "400 Bad Request\0"},
        {401, "401 Unauthorized\0"},
        {402, "402 Payment Required\0"},
        {403, "403 Forbidden\0"},
        {404, "404 Not Found\0"},
        {405, "405 Method Not Allowed\0"},
        {406, "406 Not Acceptable\0"},
        {407, "407 Proxy Authentication Required\0"},
        {408, "408 Request Timeout\0"},
        {409, "409 Conflict\0"},
        {410, "410 Gone\0"},
        {411, "411 Length Required\0"},
        {412, "412 Precondition Failed\0"},
        {413, "413 Payload Too Large\0"},
        {414, "414 URI Too Long\0"},
        {415, "415 Unsupported Media Type\0"},
        {416, "416 Range Not Satisfiable\0"},
        {417, "417 Expectation Failed\0"},
        {418, "418 I'm a teapot\0"}, // haha
        {421, "421 Misdirected Request\0"},
        {422, "422 Unprocessable Entity\0"}, // WebDAV
        {423, "423 Locked\0"}, // WebDAV
        {424, "424 Failed Dependency\0"},
        {426, "426 Upgrade Required\0"}, // TLS
        {428, "428 Precondition Required\0"},
        {429, "429 Too Many Requests\0"},
        {431, "431 Request Header Fields Too Large\0"},
        {451, "451 Unavailable For Legal Reasons\0"}, // FBI!
        
        // Server Errors
        {500, "500 Internal Server Error\0"},
        {501, "501 Not Implemented\0"},
        {502, "502 Bad Gateway\0"},
        {503, "503 Service Unavailable\0"},
        {504, "504 Gateway Timeout\0"},
        {505, "505 HTTP Version Not Supported\0"},
        {506, "506 Variant Also Negotiates\0"},
        {507, "507 Insufficient Storage\0"}, // WebDAV
        {508, "508 Loop Detected\0"}, // WebDAV
        {510, "510 Not Extended\0"},
        {511, "511 Network Authentication Required\0"}
    };
    
    unordered_map<string, string> content_type = {
        {"png", "image/png"},
        {"gif", "image/gif"},
        {"jpg", "image/jpeg"},
        {"jpeg", "image/jpeg"},
        {"html", "text/html"},
        {"xml", "text/xml"},
        {"js", "application/javascript"}
    };
}

