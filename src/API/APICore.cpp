#include "APICore.h"

APICore::APICore(CharString modfolder, CharString logfile){
    this->modfolder = modfolder;
    this->logs = Logger(logfile, "APICore", true, false, true);
}

APICore::APICore(){
    
}


// Module management
LinkedList<APIMod*> APICore::preloadMods(){ // pre-loads mod files and dependencies chains
    // open each mod folder and load
    LinkedList<APIMod*> toload; // fully working ones listed here
    LinkedList<APIMod*> mlist; // temporary list
    
    
    
    struct dirent *entry;
    DIR *dir = opendir(modfolder.get());

    if (dir == NULL){
        cout << "Selected mod folder not a folder... " << modfolder << endl;
        return toload;
    }
    while ((entry = readdir(dir)) != NULL) {
        CharString ename = entry->d_name;
        CharString s = modfolder.clone();
        if(!s.endsWith("/"))
            s.concata("/");
        s.concata(ename);
        
        if(ename.endsWith(".zip")){
            APIMod* mod = new APIMod(s);
            cout << "Opening mod zip file: " << ename << endl;
            mod->iszip=true;
            mod->loadProperties();
            mlist.add(mod);
        }else{
            // folder-mod?
            DIR *dir = opendir(s.get()); // test for folder
            if(dir != 0x0){
                APIMod* mod = new APIMod(s);
                mod->isfolder = true;
                mod->loadProperties();
                mlist.add(mod);
            }else{
                cout << "could not open mod file/folder at " << s << endl;
            }
        }
    }
    closedir(dir);
    
    
    // check dependencies
    
    
    return toload;
}

void APICore::loadMods(LinkedList<APIMod*> mods){ // begins the process to load all of the mods
    mods.freeze();
    for(int i=0;i<mods.frozenlen;i++){
        APIMod* mod = mods.frozen[i];
    }
}

void APICore::unloadMods(){ 
    
}


APIMod* APICore::preloadModule(CharString file){ // preloads the module, reads "mod.properties" file.
    
}

bool APICore::loadModule(CharString file){ // load a module from a file or folder. false if not loaded.
    
}

bool APICore::unloadModule(APIMod* mod){ // unload a module. false if kept loaded.
    
}

// Master module functions (Sent to actual implementation via APIMod)
void APICore::_onInit(){ // runs after a module is loaded.

    onInit(); // init base
    LinkedList<APIMod*> mods = preloadMods(); // check mods
    loadMods(mods); // load the mods
}

void APICore::_onEnable(){ // runs to tell the module to turn "on" and start processing.
    
    onEnable();
}

void APICore::_onDisable(){ // runs to tell the module to turn "off". (Does not actually stop, mod dev has to do it)
    
    onDisable();
}

void APICore::_onUnload(){ // runs when module is stopping.
    unloadMods();
    
    // Save data?
    
    onUnload();
}


// Getters
APIEventRegistry* APICore::getEvents(){
    return &events;
}

APIPermissionsRegistry* APICore::getPermissions(){
    return &perms;
}

Logger* APICore::getLogger(){ // General logger used by this API
    return &logs;
}

