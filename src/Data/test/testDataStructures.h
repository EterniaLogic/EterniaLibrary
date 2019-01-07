#ifndef DATA_TEST_H_00
#define DATA_TEST_H_00
#include <ctime>

#include "../BitMap.h"
#include "../FileCache.h" // hpp files are just header files + source files combined. Useful for template classes.
#include "../HashMap.hpp"
#include "../Heap.h"
#include "../IntegerList.h"
#include "../LinkedList.hpp"
#include "../PriorityQueue.h"
#include "../Queue.h"
#include "../Stack.h"
#include "../TreeList.h"
#include "testPType.h"
#include "testAbstractDB.h"
#include "../Concurrent/ConcurrentLinkedList.hpp"


void testFileCache();
void testDataStructures();
bool testDataStructureMemoryLeaks();

#endif
