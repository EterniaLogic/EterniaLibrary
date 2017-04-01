#ifndef VOXEL_GEOM_H
#define VOXEL_GEOM_H

#include "Block.h"

// Voxel 2D/3D defines a destructable 2d landscape.
// The 2D world can be loaded/saved dynamically from a memory map.


// x/z used for horizontal, y is vertical.
//  in 2D worlds, x/y are visualized, z is the Z-index.



class VoxelGeom{
private:
    char layers;
    int sizex;
    int sizey;
    CharString memmap;
    bool useMemMap;
    
    // Yeah, that's right. 3 stars.
    //  A 3-size pointer is BAD for memory space. This is why there is a memory map option.
    //  3-size pointers can be guaranteed to have memory leaks.
    Block ***blocks;
    
    
    // Thread which manages data transfer to/from memory mapper file.
    void memoryThread();
    
public:
    // FileMap is used even if MemMap is set.
    // sizex, sizey, layers are only set once.
    VoxelGeom(char layers, CharString filemap, bool useMemMap);
    
    // get a block from the system
    Block* getBlock(int x, int y, int z, int layers);
    
    // set a block
    void setBlock(int x, int y, int z, Block* block);
    
    
    // flush data from buffer to a file
    //      no point in using this if "useMemMap" = true
    void flush();
};


#endif
