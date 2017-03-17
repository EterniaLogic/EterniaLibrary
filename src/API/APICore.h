#ifndef APICore_H_
#define APICore_H_

#include "APIEventRegistry.h"
#include "APIPermissionsRegistry.h"
#include "../Data/Logger/Logger.h"
#include "../Data/LinkedList.hpp"


// The Developer makes a single instance of this within the game or program. It allows
//  for multiple mods, modules, parts of the program to be loaded dynamically.
//  This allows for limitless modding of a game depending on what permissions a
//  game developer gives players or other modules.

// This API may also be used in a larger combined system to control sub-modules.


// mod code using C/C++/Go may just be a throw-in single dynamic library file
// mod code using scripting languages can be in a single compressed zip/jar file.
// the decompression/execution of the code is handled in the implementation for 
//  the API core is not handled in this library.


class APICore{
private:
    APIEventRegistry events; // registry for event listeners
    APIPermissionsRegistry perms; // permissions registry
    LinkedList<APIMod> mods; // loaded mods
    Logger logs;
    
    
//    LinkedList<APIObjectList> objects; // object registry
public:
    APICore(CharString modfolder, CharString logfile);
    
    // Module management
    void preloadMods(); // pre-loads mod files and dependencies chains
    void loadMods(); // begins the process to load all of the mods
    
    
    APIMod* preloadModule(CharString file); // preloads the module, reads "mod.properties" file.
    
    bool loadModule(CharString file); // load a module from a file or folder. false if not loaded.
    bool unloadModule(APIMod* mod); // unload a module. false if kept loaded.
    
    // Master module functions (Sent to actual implementation via APIMod)
    void onInit(); // runs after a module is loaded.
    void onEnable(); // runs to tell the module to turn "on" and start processing.
    void onDisable(); // runs to tell the module to turn "off". (Does not actually stop, mod dev has to do it)
    void onUnload(); // runs when module is stopping.
    
    // Getters
    APIEventRegistry* getEvents();
    APIPermissionsRegistry* getPermissions();
    Logger* getLogger(); // General logger used by this API
};

#endif

