#ifndef APICore_H_
#define APICore_H_

#include <iostream>
#include <sys/types.h>

#if defined(_WIN64) || defined(_WIN32)
#define WINDOWSXX
#define byte win_byte_override  // Rename 'byte' before including windows.h
#include <windows.h>
#undef byte                    // Restore 'byte' so C++ std::byte works again
#else
#define LINUXXX
#include <dirent.h>
#endif

#include "../Data/LinkedList.hpp"
#include "../Data/Logger/Logger.h"
#include "APIEventRegistry.h"
#include "APIPermissionsRegistry.h"




#include "APIUser.h"

#ifndef APIMod_H_ // prevent infinitely nested headers
#include "APIMod.h"
#else
class APIMod;
#endif




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
    LinkedList<APIMod*> mods; // loaded mods

    Logger logs;
    CharString modfolder;
    CharString name; // name of the Game/Simulation, etc


//    LinkedList<APIObject*> objects; // object registry
    void startOnTick(double tickrate); // starts a thread for _onTick(); based on ticks-per-second.

    // Module management
    LinkedList<APIMod*> preloadMods(); // pre-loads mod files and dependencies chains
    void loadMods(LinkedList<APIMod*> mods); // begins the process to load all of the mods
    
    void checkModUpdates(LinkedList<APIMod*> mods);
    void unloadMods();

    // single mods
    APIMod* preloadModule(CharString file); // preloads the module, reads "mod.properties" file.
    bool loadModule(CharString file); // load a module from a file or folder. false if not loaded.
    bool unloadModule(APIMod* mod); // unload a module. false if kept loaded.

protected:
    // Master module functions (Sent to actual implementation via APIMod)
    void _onInit(); // runs after a module is loaded.
    void _onEnable(); // runs to tell the module to turn "on" and start processing.
    void _onLoadMods(); // loads all mods
    void _onDisable(); // runs to tell the module to turn "off". (Does not actually stop, mod dev has to do it)
    void _onUnload(); // runs when module is stopping.
    void _onTick(double seconds); // runs a tick command on all mods. calls onTick(seconds);
    
public:
    APICore(CharString name, CharString modfolder, CharString logfile);
    APICore();
    virtual ~APICore(){}

    // Global Start/Stop
    void Init(); // run _onInit(), _onEnable(),
    void ResumeTick(); // Start ticking time (called _onEnable())
    void PauseTick(); // Stop ticking time (Used for menus or w/e to stop time)
    void Stop(); // Quit

    // inherritance
    virtual void onInit(){} // initial start of the system, called by (start())  ->  _onInit();
    virtual void onEnable(){} // resumes ticks, Core, mods, etc.
    virtual void onLoadMods(){} // load other mods manually?
    virtual void onDisable(){} // disabling / pausing ticks, Core, mods, etc.
    virtual void onUnload(){} // closing down
    virtual void onTick(double seconds){} // Global tick timer, useful for game timing or w/e. (Mods already get ticked in _onTick(double seconds);

    virtual void checkModUpdates(){} // tell all mods to check for updates
    virtual void updateMods(){} // download and test mods along with required dependencies.

    

    // Getters
    APIEventRegistry* getEvents();
    APIPermissionsRegistry* getPermissions();
    Logger* getLogger(); // General logger used by this API
};

#else
class APICore;
#endif

