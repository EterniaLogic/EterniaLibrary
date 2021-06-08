// Configuration for tests
#ifndef TESTCONFIG
#define TESTCONFIG

#include "../Data/Logger/Logger.h"

#define TFLINE() CharString tflinex = __FILE__; \
    tfline << __LINE__;

class TestConfig{
public:
    static Logger log; // test log
    static bool exit_on_fail;
    
    static void init();
    
    static void fail(CharString fline); // fail location, file/line, class, etc.
    static void success();
};

#endif
