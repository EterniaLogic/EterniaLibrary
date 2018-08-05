#ifndef GEOM2d_H_
#define GEOM2d_H_

#include "Chunk.h"
#include "Block.h"

#include "../../Data/includes.h"

// Voxel 2D/3D defines a destructable 2d landscape.
// The 2D world can be loaded/saved dynamically from a memory map.


// x/z used for horizontal, y is vertical.
//  in 2D worlds, x/y are visualized, z is the Z-index.



class Geometry2D{
private:
    char layers;
    int sizex;
    int sizey;
    CharString memmap_folder; // memory may folder
    bool useMemMap;
    
    //  A 2-size pointer is BAD for memory space. This is why there is a memory map option.
    //  2-size pointers can be guaranteed to have memory leaks.
    Chunk **chunks;
public:
    // FileMap is used even if MemMap is set.
    // sizex, sizey, layers are only set once.
    Geometry2D(int width, int height);
    
    // get a block from the system
    Block* getBlock(int x, int y);
    
    // set a block
    void setBlock(int x, int y, Block* block);
    
    
    // flush data from buffer to a file
    //      no point in using this if "useMemMap" = true
    void flush();
};


#endif
