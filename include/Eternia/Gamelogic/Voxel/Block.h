#ifndef BLOCKx_H
#define BLOCKx_H


// Block2D/3D
class Block{
private:
    int id;
public:
    BlockID(int id){
        this->id = id;
    }
    
    int getID(){
        return id;
    }
};

#endif
