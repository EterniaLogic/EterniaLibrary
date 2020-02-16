#ifndef FileManager_H_
#define FileManager_H_

#include "../Backend.h"
#include "../../../Data/includes.h"


// The File Manager serves files to clients following ftp, http or other standards.

// SPEC uses a specific protocol
// AUTO detects a client's protocol automatically upon the first message.
enum FILEMAN_TYPE {FMT_HTTP, FMT_FTP, FMT_SPEC, FMT_AUTO};

class FileManager : public Backend{

public:
    FileManager(CharString directory);

};

#endif
