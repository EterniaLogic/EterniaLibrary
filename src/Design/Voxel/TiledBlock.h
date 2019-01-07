#ifndef TILEDBLOCK_H_
#define TILEDBLOCK_H_

#include "Block.h"

// Tiled Blocks are expensive, as they must keep extra data for code that is running for them.
// Tiled Blocks can have multiple layers (for wires, etc) AND be ticked to run external code on them.

// Z=0 in layeredBlocks means the back layer from view to set a standard.


// Standard usage of TiledBlocks would be for blocks that have wires or pipes going through them.
//  TiledBlocks may also run tick-able code.

class TiledBlock : public Block{
public:
    LinkedList<Block> layeredBlocks;
    CharString data; // data used for events in tick
    int x,y,z;
    
    TiledBlock(uint32_t id, int _x, int _y, int _z){
        // id
        addSerial(&layeredBlocks, "LayeredBlocks", SSE_LinkedList);
        x=_x;
        y=_y;
        z=_z;
    }
    
    // Events (override with other blocks)
    void tick(double seconds){}
    void draw(double seconds){}
};

#endif
