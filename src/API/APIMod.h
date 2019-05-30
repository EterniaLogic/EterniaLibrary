#ifndef APIMod_H_
#define APIMod_H_

#include "../Data/CharString.h"
#include "../Parsing/LoadFile.h"
#include "../Parsing/SimpleParser.h"
#include "APIEventRegistry.h"
#include "APICore.h"

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
// Shared - Used on any system
// Node - Distributed node (Processes data, store or transmit, specific id is decided by the dev)
enum APIModType {APIMT_Server, APIMT_Client, APIMT_Shared, APIMT_Node};

class APIModVersion{
public:
    int major, minor, submajor, subminor; // enables up to 4 major/minors
    bool atleastver; // '>v1.1' using greater than versionid
    CharString versionstring; // original version string
    APIModVersion(CharString versionstr);
    APIModVersion(); // assume 0.0.0.0
    virtual ~APIModVersion();
    
    bool compareVersion(APIModVersion version);
    
    // returns a version that is easier to compare
    double getLongVersion();
};

// The great thing about making an API like this, is that it allows for mods to have a limited access
//  to other mods that are not dependencies.

// A database mod shouldnt be accessed by a logging mod.

class APIMod : public APIUser{
private:
    bool loaded, inited, propertiesloaded;

public:
    // private data stored for this module.
    APICore* core; // Linked core
    CharString file, language, versionstr; // version string does not include unixname
    APIModVersion version; // comparable version class
    //CharString name; // inherited from APIUser
    CharString unixname; // simple name alphaneumeric-only name (for use with dependency version, folder name, mod mentions, etc.)
    LinkedList<APIMod*> dependencies;
    LinkedList<CharString> dependencyversions; // "mod1:v1.002.1", "mod2:v01283092"
    APIModType type;
    CharString modcwdloc; // CWD directory for mod
    bool isfolder, iszip;
    
    
    


    // location for scripts, mod name, language, version
    APIMod(APICore* core, CharString loc); //, CharString name, CharString language, CharString version);
    APIMod(APICore* core);
    APIMod();

    virtual ~APIMod();

    // Same as the initializer, used if main initializer isn't used.
    void init(CharString file);
    void initdependencies(CharString file);
    void loadProperties(); // loads from mod.properties
    bool compareVersionString(CharString verstr); // compare request "modname:versionstr" from another mod/core

    virtual CharString getModFileData(CharString modfile); // within zip file?

    // API language implementation functions.
    virtual void onInit(); // initializes dependencies?
    virtual void onLoad();
    virtual void onEnable();
    virtual void onDisable();
    virtual void onUnload(); // C/C++/Go modules cannot be directly unloaded.
    virtual void onReload(); // reload configs

    // Automatic updates (called every day or so)
    virtual void onCheckUpdates(); // check for updates online via GitHub or other.
    virtual void onUpdate(); // download update.

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
    CharString getVersionString(); // get the versions of the module
    APIModVersion getVersion(); // get the versions of the module
    CharString getConfigDir(); // specific dir string for the directory
    CharString getDataDir();
    CharString getLogDir();
    
    LinkedList<CharString> getMissingDependencies(LinkedList<APIMod*> othermods);
    bool compareModDependencies(LinkedList<APIMod*> othermods);
    int countDependencies(); // mods that this mod depends on.
    
    
    LinkedList<APIMod*> tmp_dependents; // temporary list for using countModDependents
    int countModDependents(); // outputs number of mods that use this mod (USES tmp_dependents)


    // Cross-memory referencing (Heavily required to make a good API)
    // Good language implementations can allow these to almost seem like real-time
    //  values in the API.

    // if "mod" is null, the core module is referenced.
    void* getValue(APIMod* mod, CharString valname); // retrieve a value
    void* getClass(APIMod* mod, CharString classN); // retrieve a class

    bool setValue(APIMod* mod, CharString valname, void* val);
};

#else
class APIMod;
#endif

