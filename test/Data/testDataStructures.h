#ifndef DATA_TEST_H_00
#define DATA_TEST_H_00
#include <ctime>

#include "../../src/Data/BitMap.h"
#include "../../src/Data/FileCache.h" // hpp files are just header files + source files combined. Useful for template classes.
#include "../../src/Data/HashMap.hpp"
#include "../../src/Data/Heap.h"
//#include "../IntegerList.h"
#include "../../src/Data/LinkedList.hpp"
#include "../../src/Data/PriorityQueue.h"
#include "../../src/Data/Queue.h"
#include "../../src/Data/Stack.hpp"
#include "../../src/Data/TreeList.h"
#include "testPType.h"
#include "testAbstractDB.h"
#include "../../src/Data/Concurrent/ConcurrentLinkedList.hpp"


void testFileCache();
void testDataStructures();
bool testDataStructureMemoryLeaks();

#endif
