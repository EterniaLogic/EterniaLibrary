#ifndef CHUNKLOADER_H_
#define CHUNKLOADER_H_

#include "../../Data/includes.h"
#include "Chunk.h"

// ChunkLoaders work tirelessly in the background to load in requested chunks

class ChunkLoader{
public:
    int maxloaded;
    Queue chunkRequests;
    
    ChunkLoader(CharString chunkfolder, int maxloaded);
    
    
};

#endif
