Data Structures are a method to organize data in a efficient approach. Every Data Structure has it's purpose for a general or specific task.



Generic Structures
=====

***Lists***

Store data that has an add/remove approach
* [ArrayList](arraylist.md)
* [CyclicList](cycliclist.md)
* [DoubleList](doublelist.md)
* [LinkedList](linkedlist.md)
* [HashTable](hashtable.md)

* [FileCache](filecache.md) (insecure RAM-like structure that uses a file for a list)
* [SecureFileCache](securefilecache.md) (AES or encrypted file-list)

* [Queue](queue.md)
* [PriorityQueue](priorityqueue.md)
* [Stack](stack.md)
* [TreeList](treelist.md)


***Maps***

Maps enable data to be stored with a 'key, name' approach.
* [HashMap](hashmap.md)
* [LinkedMap](hashmap.md)
* [BitMap](bitmap.md) (Used for images with xy=value coordinates)


***Types***

Special Types enable for big data or polymorphic 'easy' variables.
* [CharString](charstring.md) (Main String implementation, including conversion from numbers)
* [CRCData](crcdata.md)
* [DynamicType](dynamictype.md) (python-like variables)
* [UInt512](uint512.md) (broken)

***Sorting***

* [Heap](arraylist.md)



***Generic Simulation objects***

* [Location](location.md) (XYZ Coordinates with name and dimension)
* [Object](object.md) (polymorphic object, useful for debug reporting in simulation)

**Other**

* [FileSystem](filesystem.md)
* [Graph](graph.md)

Special Types
===

* [Concurrent](concurrent/index.md) (concurrent data types, such as CopyOnWriteArrayList, ConcurrentLinkedList, ThreadPool, etc.)
* [Database](database.md) (broken-ish, database implementation)
* [Event Handler](eventhandler.md) (Full Event timing and execution suite)
* [File Format](fileformat/index.md) (CSV, MTL, OBJ, XML types)
* [Logger](logger.md)
* [ProtectType](protecttype.md) (PType, used to detect and prevent memory hacking, including honeytraps)


