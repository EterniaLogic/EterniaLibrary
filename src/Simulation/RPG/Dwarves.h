#ifndef DWARVES_H_
#define DWARVES_H_

#include "../Society/include.h"
#include "../../Data/LinkedList.hpp"
#include "../../API/APICore.h"
#include "../../API/APIMod.h"
#include "Entities/Creature/Mortal/Dwarf.h"

// Dwarf is a simulation attempt for the backend of a 2D Z-axis game following a dwarven city builder.
// This class is inherrited in the main application for ticking GUI/2D.
class Dwarves : public APICore{
private:
    /*      inherrited from APICore
    APIEventRegistry events;
    APIPermissionsRegistry perms;
    LinkedList<APIMod*> mods;
    Logger logs;
    */
public:
    Dwarves* instance;
    LinkedList<Dwarf*> dwarves;
    LinkedList<Race*> races;
    bool tentities, ttiles, tevent, tfps; // do tick? Syncronizer.
    
    Dwarves();
    
    
    void initTestSim(); // initialize simulation
    void initraces(); // initialize races and their castes
    
    void tickEntities(double seconds); // dwarves / monsters
    void tickEntityMove(double seconds); // Moving entities
    void tickTiles(double seconds); // 2D tiles
    void tickActions(double seconds); // Entity actions
    void tickMods(double seconds); // manage mod idle ticks
    
    void tick(double seconds); // master tick
    
    
    void onInit();
    void onEnable();
    void onDisable();
    void onUnload();
    
    // External
    void tickLighting(double seconds){ } // 2D cell shading
    void tickEvents(double seconds){ } // Mouse move, keyboard, etc.
    void tickDraw(double seconds){ } // handled by an external drawing program outside of this library
    void tickFPS(double seconds){ } // ticked every second and reports FPS of other threads (Inherrited)
};

#endif
