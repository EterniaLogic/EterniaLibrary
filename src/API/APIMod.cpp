#include "APIMod.h"

APIModVersion::APIModVersion(){
    major = minor = submajor = subminor = 0;
    atleastver = false;
}

APIModVersion::APIModVersion(CharString versionstr){ // discards name split from ':', only keeps version number
    major = minor = submajor = subminor = 0;
    atleastver = false;
    
    // forget modname if it is still in the string
    if(versionstr.contains(":")){
        LinkedList<CharString> vsplit = versionstr.split(":");
        versionstr = vsplit[1];
    }
    
    this->versionstring = versionstr; // keep original string
    
    if(versionstr.startsWith(">")){
        atleastver = true;
        versionstr.shiftLeft(1);
    }
    
    if(versionstr.startsWith("v")) versionstr.shiftLeft(1);
    
    if(versionstr.contains(".")){
        LinkedList<CharString> vsplit = versionstr.split(".");
        if(vsplit[0].isValidNumber()) major = vsplit[0].getInt();
        if(vsplit[1].isValidNumber()) minor = vsplit[1].getInt();
        if(vsplit.size() >= 3 && vsplit[2].isValidNumber()) submajor = vsplit[2].getInt();
        if(vsplit.size() >= 4 && vsplit[3].isValidNumber()) subminor = vsplit[3].getInt();
    }else{
        // what? Single version number?
        if(versionstr.isValidNumber()){
            major = versionstr.getInt();
        }else{
            // dunno...
            cout << "API Mod Version could not figure out the version for " << versionstring << endl;
        }
    }
}

APIModVersion::~APIModVersion(){}

bool APIModVersion::compareVersion(APIModVersion version){
    if(atleastver && getLongVersion() >= version.getLongVersion()){
        return true;
    }else if(getLongVersion() == version.getLongVersion()){
        return true;
    }else{
        return false;
    }
}

// returns a version that is easier to compare
double APIModVersion::getLongVersion(){
    double val;
    
    val += subminor;
    val += submajor*1000; // most versioning systems do not go above 1000
    val += minor*1000000;
    val += major*1000000000;
    
    return val;
}





APIMod::APIMod(APICore* core, CharString file){
    this->core = core;
    permscope = P_MOD;
    loaded = propertiesloaded = inited = false;
    isfolder = iszip = false;
    this->file = file;
    type=APIMT_Server;
}

APIMod::APIMod(APICore* core){
    this->core = core;
    permscope = P_MOD;
    loaded = propertiesloaded = inited = false;
    isfolder = iszip = false;
    type=APIMT_Server;
}

APIMod::APIMod(){
    this->core = 0x0;
    permscope = P_MOD;
    loaded = propertiesloaded = inited = false;
    isfolder = iszip = false;
    type=APIMT_Server;
}

APIMod::~APIMod(){
    onUnload();
}



void APIMod::init(CharString file){ // , CharString name, CharString language, CharString version
    this->file = file;
    loadProperties();


    onInit();
    inited=true;
}

// LinkedList<LinkedList<CharString>> lines = SimpleParseFile(file, '\n');
void APIMod::loadProperties(){ // , CharString name, CharString language, CharString version
    if(propertiesloaded) return;

    LinkedList<LinkedList<CharString>> lines = SimpleParseString(getModFileData("mod.properties"), '=');

    CharString depvers = "";
    LinkedListIterator<LinkedList<CharString>> lineit = lines.getIterator();
    while(lineit.hasNext()){
        LinkedList<CharString> p = lineit.next();
        CharString pname = p[0];
        if(pname.compare(CharString("name")))
            this->name = p[1];
        else if(pname.compare(CharString("unixname")))
            this->unixname = p[1];
        else if(pname.compare(CharString("language"))) // c++, java, etc.
            this->language = p[1];
        else if(pname.compare(CharString("version"))){
            this->versionstr = p[1];
            this->version = APIModVersion(p[1]);
        }else if(pname.compare(CharString("dependency_versions")))
            depvers = p[1];
    }

    this->modcwdloc = unixname; // relative folder location for mod
    
    // load dependency versioning information
    //      this->dependencyversions.add("mod1:v12938");
    if(depvers.getSize() > 3){
        if(depvers.contains(", ")){
            depvers.replace((char*)" ", (char*)"");
            LinkedList<CharString> v = depvers.split(",");
            this->dependencyversions.addAll(v);
        }else{
            this->dependencyversions.add(depvers);
        }
    }


    propertiesloaded=true;
}

bool APIMod::compareVersionString(CharString verstr){
    LinkedList<CharString> spl = verstr.split(":");
    CharString name = spl[0];
    CharString ver = spl[1];
}

// within zip file or folder?
CharString APIMod::getModFileData(CharString modfile){
    // only support folders here, use inheritance to load zip files

    if(isfolder){
        CharString filex = file.clone();
        filex.concata("/");
        filex.concata(modfile);
        cout << "Reading mod folder file: " << filex << endl;
        return fileReadAll(filex);
    }else{
        cout << "could not open Mod File Data " << modfile << endl;
    }
    return "";
}

// figure out what mods have good dependencies
bool APIMod::compareModDependencies(LinkedList<APIMod*> othermods){
    LinkedListIterator<CharString> depstrs = dependencyversions.getIterator();
    
    while(depstrs.hasNext()){
        CharString depstr = depstrs.next();
        if(depstr.contains(":")){
            LinkedListIterator<APIMod*> modit = othermods.getIterator();
            while(modit.hasNext()){
                APIMod *mod = modit.next();
                // compare direct
                if(! version.compareVersion(mod->version)){
                    // not the same or and older version
                    return false;
                }
            }
            
        } // else invalid!
    }
    return false;
}

// return a list of dependencies with name:version string for missing/different version mods.
LinkedList<CharString> APIMod::getMissingDependencies(LinkedList<APIMod*> othermods){
    LinkedList<CharString> strs;
    LinkedListIterator<CharString> depstrs = dependencyversions.getIterator();
    
    while(depstrs.hasNext()){
        CharString depstr = depstrs.next();
        if(depstr.contains(":")){
            LinkedListIterator<APIMod*> modit = othermods.getIterator();
            bool identified = false;
            while(modit.hasNext()){
                APIMod *mod = modit.next();
                // compare direct
                if(unixname.compare(mod->unixname) && version.compareVersion(mod->versionstr)){
                    // not the same or and older version
                    identified = true; // same
                    break;
                }
            }
            
            if(!identified){
                strs.add(depstr); // "mod:version"
            }
            
        } // else invalid!
    }
    
    return strs;
}

int APIMod::countDependencies(){
    return dependencyversions.size();
}

int APIMod::countModDependents(){
    int dep = 0;
    // tmp_dependents

    return dep;
}

// NOT IMPLEMENTED HERE, use inheritance and declare there


void APIMod::onInit(){

}

// API language implementation functions.
void APIMod::onLoad(){
    loaded=true;
}

void APIMod::onEnable(){

}

void APIMod::onDisable(){

}

// C/C++/Go modules cannot be directly unloaded.
void APIMod::onUnload(){

}

// reload configs
void APIMod::onReload(){

}



// Synchronized functions run in the render thread
// [Client-Side SYNC] specific function that enables openGL contexts
void APIMod::onGuiDraw(){

}

// [Client-Side SYNC] Draw 3D things
void APIMod::onRenderDraw(){

}

// [Client-Side SYNC] draw a specific shader
void APIMod::onShader(){

}

// Node-Side (Nodes are sub-servers)
// Node processing
void APIMod::onNodeTick(){

}

// Shared
void APIMod::onNetworkTick(){

}

// Server-side (or cross tracking)
// time between ticks given to script engines
void APIMod::onTick(double time){

}

// send an event to the scripts
Event APIMod::onEvent(Event event){

	return event;
}

// Automatic updates (called every day or so)
void APIMod::onCheckUpdates(){ // check for updates online via GitHub or other.

}

void APIMod::onUpdate(){ // download update.
}


// internal systems (Compiled languages still need an API)
// add a class for use by scripts
void APIMod::addClass(int size){

}

// add a function for use by scripts
void APIMod::addFunction(void* func, int params){

}

// compileable languages can be dynamically compiled, others will just run a check
void APIMod::compile(){

}

// any type of script
// stop the script engine (Unloads script, attempts to unload DLL)
void APIMod::stop(){

}

// start the script engine (Loads the script, preps modules)
void APIMod::start(){

}

// runs Stop() then Start()
void APIMod::restart(){

}

// clear garbage (For specific languages, such as java and C#)
void APIMod::gc(){

}

CharString APIMod::getName(){
    return name;
}

CharString APIMod::getLanguage(){return language;} // get the language of the module (e.g: C++, Lua, ect.)
CharString APIMod::getVersionString(){return versionstr;} // get the versions of the module
APIModVersion APIMod::getVersion(){return version;} // get the versions of the module
CharString APIMod::getConfigDir(){return modcwdloc;} // specific dir string for the directory
CharString APIMod::getDataDir(){return modcwdloc+"/data";}
CharString APIMod::getLogDir(){return modcwdloc+"/log";}
