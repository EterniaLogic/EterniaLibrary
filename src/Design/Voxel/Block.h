#ifndef BLOCKx_H
#define BLOCKx_H

#include "../../Serialization/SpecificSerializer.h"
// Blocks define a very basic XYZ coordinate and normally have very little data loaded unless they are special.
//  this saves on data usage to simulate a block.

// use TiledBlock for more advanced functionality

// ID -1 is air.

// Block2D/3D
class Block : public SpecificSerializer {
private:
    int32_t id;
public:
    Block(){ 
        id = -1;  // set air
        addSerial(&id, SSE_Int); // automated serialization
    }
    Block(int32_t id){
        this->id = id;
    }
    
    ~Block(){}
    
    int32_t getID(){
        return id;
    }
};

#endif
