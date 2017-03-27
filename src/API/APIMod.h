#ifndef APIMod_H_
#define APIMod_H_

#include "../Data/CharString.h"
#include "APIEventRegistry.h"
#ifndef APICore_H_
    #include "APICore.h"
#else
    class APICore;
#endif

// Core header for a mod.
//  Actual module using C++ can use this directly via inheritance. (C++ loaded .dll/.so on runtime)
//  Otherwise, this core acts as an intermediary for other loaded file languages.

// Other languages use "mods" as a language entirely to itself and dependencies/linking data are managed here.
//  This allows for any scripting/programming language to be programmed and data can be cross-linked.

// Actual detection of data, classes need to be handled by the implementations.
// Basic data can be interchanged, but for now it will just be "void *"


// Scripts are sorted into distributables based off of the script types.
// Server - Main server
// Client - Game Client
// Node - Distributed node (Processes data, store or transmit, specific id is decided by the dev)
enum APIModType {APIMT_Server, APIMT_Client, APIMT_Shared, APIMT_Node};

// The great thing about making an API like this, is that it allows for mods to have a limited access
//  to other mods that are not dependencies.

// A database mod shouldnt be accessed by a logging mod.

class APIMod{
private:
    // private data stored for this module.
    APICore* core; // Linked core
    CharString file, name, language, version;
    LinkedList<APIMod> dependencies;
    APIModType type; // Type derived from the mod file
public:
    APIMod(CharString file, CharString name, CharString language, CharString version);
    APIMod();
    
    virtual ~APIMod();
    
    // Same as the initializer, used if main initializer isn't used.
    void init(CharString file, CharString name, CharString language, CharString version);
    
    // API language implementation functions.
    virtual void onLoad();
    virtual void onEnable();
    virtual void onDisable();
    virtual void onUnload(); // C/C++/Go modules cannot be directly unloaded.
    virtual void onReload(); // reload configs
    
    
    
    // Client-Side
    virtual void onGuiDraw(); // [SYNC] specific function that enables openGL contexts
    virtual void onRenderDraw(); // [SYNC] Draw 3D things
    virtual void onShader(); // [SYNC] draw a specific shader
    
    // Node-Side (Nodes are sub-servers)
    virtual void onNodeTick(); // Node processing
    
    // Shared
    virtual void onNetworkTick();
    
    // Server-side (or cross tracking)
    virtual void onTick(double time); // time between ticks given to script engines
    virtual Event onEvent(Event event); // send an event to the scripts
    
    
    // internal systems (Compiled languages still need an API)
	virtual void addClass(int size); // add a class for use by scripts
	virtual void addFunction(void* func, int params); // add a function for use by scripts
	virtual void compile(); // compileable languages can be dynamically compiled, others will just run a check
    
    // any type of script
    virtual void stop(); // stop the script engine (Unloads script, attempts to unload DLL)
    virtual void start(); // start the script engine (Loads the script, preps modules)
    virtual void restart(); // runs Stop() then Start()
    virtual void gc();    // clear garbage (For specific languages, such as java and C#)
    
    
    CharString getName(); // module name
    CharString getLanguage(); // get the language of the module (e.g: C++, Lua, ect.)
    CharString getVersion(); // get the versions of the module
    CharString getConfigDir(); // specific dir string for the directory
    CharString getDataDir();
    CharString getLogDir();
    
    
    // Cross-memory referencing (Heavily required to make a good API)
    // Good language implementations can allow these to almost seem like real-time
    //  values in the API.
    
    // if "mod" is null, the core module is referenced.
    void* getValue(APIMod* mod, CharString valname); // retrieve a value
    void* getClass(APIMod* mod, CharString classN); // retrieve a class
    
    bool setValue(APIMod* mod, CharString valname, void* val);
};

#endif

