#include "APICore.h"

APICore::APICore(CharString name, CharString modfolder, CharString logfile){
    this->name = name;
    this->modfolder = modfolder;
    cout << "construct APICore" << endl;
    this->logs = Logger(logfile, "APICore", true, false, true);
    cout << "construct APICore end" << endl; cout.flush();
}

APICore::APICore(){

}


APIMod* createDirMod(APICore* core, CharString folder, CharString ename) {

	CharString mpath = "";
	mpath.concata(folder);
	mpath.concata("/");
	mpath.concata(ename);

	LinkedList<APIMod*> mlist;
	if (ename.endsWith(".zip")) {
		APIMod* mod = new APIMod(core, mpath);
		cout << "Opening mod zip file: " << ename << endl;
		mod->iszip = true;
		mod->loadProperties();
		return mod;
	}else {
		// folder-mod?

		APIMod* mod = new APIMod(core, mpath);
		mod->isfolder = true;
		mod->loadProperties();
		return mod;
	}
}

LinkedList<CharString> getDirListing(CharString loc) {
	LinkedList<CharString> list;
#ifdef WINDOWSXX // Windows-only
	std::string pattern(modfolder.get());
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			//createDirMod(data.cFileName);
			list.add(Data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
#elif defined(LINUXX) // Linux-only
	struct dirent* entry;
	DIR* dir = opendir(loc.get());

	if (dir == NULL) {
		cout << "Selected mod folder not a folder... " << loc << endl;
		return list;
	}
	while ((entry = readdir(dir)) != NULL) {
		list.add(entry->d_name);
	}
	closedir(dir);
#endif
	return list;
}

/*int getModDep(APIMod* mod){
    return mod->countDependencies();
}*/

int getModDependents(APIMod* mod){
    return mod->countModDependents();
}

// Module management
LinkedList<APIMod*> APICore::preloadMods(){ // pre-loads mod files and dependencies chains
    // open each mod folder and load
    LinkedList<APIMod*> toload; // fully working ones listed here
    LinkedList<APIMod*> mlist; // temporary list to figure out dependencies
    
	LinkedList<CharString> dirlist = getDirListing(modfolder);
	LinkedListIterator<CharString> it = dirlist.getIterator();
	while(it.hasNext()){
		CharString iv = it.next();
		mlist.add(createDirMod(this, modfolder, iv));
	}
    
    
    // Order mods by preloading dependencies first (First item should be a dependency-less mod or the apicore)
    LinkedListIterator<APIMod*> itm1 = mlist.getIterator();
	while(itm1.hasNext()){
	    APIMod* mod = itm1.next();
	    mod->tmp_dependents = mlist;
	}
	
    mlist.sort(&getModDependents); // sort based on dependents first (not dependencies)
    
    //mlist.sort(&getModDep); // Order mods by dependencies (Least dependencies loaded first)

    // check dependencies
	cout << "Check mod dependencies TODO" << endl;
	LinkedListIterator<APIMod*> itm2 = mlist.getIterator();
	while(itm2.hasNext()){
    	APIMod* mod = itm2.next();
    	mod->tmp_dependents.clear(); // clear from previous sort action
    	if(mod->compareModDependencies(mlist)){
    	    toload.add(mod);
    	}else{
    	    logs.log(CharString("Mod ") + mod->getName() + " did not meet dependencies. Missing: ");
    	    logs.log(CS_TAB);
    	    LinkedListIterator<CharString> depstrs = mod->getMissingDependencies(mlist).getIterator();
    	    while(depstrs.hasNext()){
    	        CharString vstring = depstrs.next();
    	        logs.log(CS_TAB+vstring);
    	    }
    	    
    	}
	}
    

    return toload;
}

void APICore::loadMods(LinkedList<APIMod*> mods){ // begins the process to load all of the mods
    LinkedListIterator<APIMod*> itm = mods.getIterator();
    while(itm.hasNext()){
        APIMod* mod = itm.next();
        
        // load?
    }
}

void APICore::checkModUpdates(LinkedList<APIMod*> mods){

}

void APICore::unloadMods(){
    // loop through mods and unload them
    LinkedListIterator<APIMod*> itm = mods.getIterator();
    while(itm.hasNext()){
        APIMod* mod = itm.next();
        mod->onDisable();
        mod->onUnload();
    }

    mods.clear();
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

void APICore::_onLoadMods(){
    // loads all mods
    CharString logtext = "";
    logtext.concata("[");
    logtext = name.clone();
    logtext.concata("] Loading mods...");
    logs.Log(logtext);

    LinkedList<APIMod*> mods = preloadMods();

    // check for udpates first
    checkModUpdates(mods);

    // full loadup
    loadMods(mods);
}

void APICore::_onDisable(){ // runs to tell the module to turn "off". (Does not actually stop, mod dev has to do it)
    // send to mods
    // ...
    onDisable();
}

void APICore::_onUnload(){ // runs when module is stopping.
    unloadMods();

    // Save data?

    onUnload();
}


// run _onInit(), _onEnable(),
void APICore::Init(){
    _onInit();
    _onEnable();
}


// Start ticking time (calls _onEnable())
void APICore::ResumeTick(){
    // send to mods
    // ...
    _onEnable();
}

// Stop ticking time (Used for menus or w/e to stop time)
void APICore::PauseTick(){
    // send to mods
    // ...
    _onDisable();
}


// Quit (calls _onDisable(), disables all mods, etc, then quits)
void APICore::Stop(){
    // send to mods
    // ...
    unloadMods();
    PauseTick();
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

