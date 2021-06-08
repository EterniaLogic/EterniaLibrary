#ifndef TESTDATASTRUCTURE
#define TESTDATASTRUCTURE

// Test a data structure based on expected input/output
// Test types:
//  - Expected input/output
//  - Memory leaks under high stress
//  - Performance limitations under high stress, following expected O(???) value

#include "../TestConfig.h"
#include "../../Data/includes.h"
//#include "../../Data/DataStructureT.h" // base type to help with testing

// 
template<class DS>
class TestDataStructure{
public:
    DS* structure;
    
    TestDataStructure();
    virtual ~TestDataStructure();
    
    bool TestMemoryLeaks(); // puts data structure under high stress, measures total program memory
    bool TestIO();
    bool TestPerformance(); // includes Time profiling
};


#endif
