#ifndef DWARVES_H_
#define DWARVES_H_

#include "../Society/include.h"
#include "../../Data/LinkedList.hpp"
#include "Entities/Dwarf.h"

// Dwarf is a simulation attempt for the backend of a 2D Z-axis game following a dwarven city builder.
class Dwarves{
public:
    Dwarves();
    
    LinkedList<Dwarf> dwarves;
    
    void initTestSim(); // initialize simulation
    
    void tickEntities(double seconds); // dwarves / monsters
    void tickTiles(double seconds); // 2D tiles
    void tickEvents(double seconds); // 2D tiles
    void tickFPS(double seconds); // ticked every second and reports FPS of other threads
    void tick(double seconds); // master syncronization tick
    
    
    void tickDraw(double seconds){ } // handled by an external drawing program outside of this library
    
    
    // Threads
    void threadTick();
};

#endif
