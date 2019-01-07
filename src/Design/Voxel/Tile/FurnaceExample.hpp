#ifndef FURNACE_EX_H_
#define FURNACE_EX_H_

#include "../TiledBlock.h"

class FurnaceItem{
public:
    bool burnable, burnt, done;
    int cooktime = 0; // cook time in seconds
    int burntime = 0; // time for item to be burnt, or amount of time to use as fuel
}

class Steak : FurnaceItem{
public:
    Steak(){
        burntime = 60;
        burnt = false;
        burnable = true;
        done=false;
    }
};

class Coal : FurnaceItem{
public:
    Coal(){
        burntime = 60; // time until fuel consumed
    }
};

class FurnaceExample : TiledBlock{
public:
    FurnaceItem item;
    FurnaceItem fuel;
    bool on;
    
    FurnaceExample(int _x, int _y, int _z){
        addSerial(&layeredBlocks, "LayeredBlocks", SSE_LinkedList);
        id = 15;
        x=_x;
        y=_y;
        z=_z;
        on = true;
        
        item = Steak();
        fuel = Coal();
    }
    
    // tick this tiled block
    void tick(double seconds){
        if(fuel.burntime > seconds){
            fuel.burntime -= seconds;
            item.cooktime += seconds;
            
            if(item.cooktime > item.burntime){
                on=false;
                if(item.burnable){
                    item.burnt = true;
                    item.burnable = false;
                }else{
                    item.done=true;
                    
                }
            }
        }
    }
    
    void draw(double seconds){
        // Draw block 2D/3D using OpenGL or whatever perspective.
    }
};

#endif
