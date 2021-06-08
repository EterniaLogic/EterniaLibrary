#ifndef TESTIF
#define TESTIF

// TestIf is used to test a condition
//  Else, an error will be reported to file 

#include "TestConfig.h"


bool TestIf__(bool val, CharString tfline){
    
    if(val){
        
    }else{
        // on failure
        
        TestConfig::fail(tfline);
    }
    
    return val; // only returns if the test config enables continue on failure
}


#define TestIf(value) \
    TFLINE() \
    TestIf__(value, tfline);

#endif
