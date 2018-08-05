#ifndef CHUNK_H_
#define CHUNK_H_

#include "Block.h"
// Chunks are collections of N/N/N blocks that are used as a standard for file sizes of blocks

class Chunk{
private:
    Block ***blocks;
    int x,y,z; // chunk location
public:
    static const int width=16, depth=16, height=256; // Standard Minecraft chunk sizes
    
    // initializes blocks with air blocks
    Chunk();
    
    
    // gets
    int getX();
    int getY();
    int getZ();
    
    void tick(double seconds); // tick all Tiled Blocks for seconds
};

#endif
