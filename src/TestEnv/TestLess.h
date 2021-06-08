#ifndef TESTLESS
#define TESTLESS

// TestLess is used to test if value1 is less than value2

#include "TestConfig.h"


// Test if val1 is less than value 2
bool TestLess__(double val, double val2, CharString tfline){
    
    if(val < val2){
        TestConfig::success(); // test if this is wanted?
    }else{
        // on failure
        
        TestConfig::fail(tfline);
    }
    
    return val; // only returns if the test config enables continue on failure
}


#define TestLess(value, value2) \
    TFLINE() \
    TestLess__(value, value2, tfline);

#endif
