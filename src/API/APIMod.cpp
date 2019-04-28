#include "APIMod.h"

APIMod::APIMod(CharString file){
    permscope = P_MOD;
    loaded = propertiesloaded = inited = false;
    isfolder = iszip = false;
    this->file = file;
}

APIMod::APIMod(){
    permscope = P_MOD;
    loaded = propertiesloaded = inited = false;
    isfolder = iszip = false;
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
        if(pname.Compare("name"))
            this->name = p[1];
        else if(pname.Compare("unixname"))
            this->name = p[1];
        else if(pname.Compare("language"))
            this->language = p[1];
        else if(pname.Compare("version"))
            this->language = p[1];
        else if(pname.Compare("dependency_versions"))
            depvers = p[1];
    }
    
    
    // load dependency versioning information
    //      this->dependencyversions.add("mod1:v12938");
    if(depvers.getSize() > 3){
        if(depvers.contains(", ")){
            depvers.replace(" ", "");
            LinkedList<CharString> v = depvers.split(",");
            this->dependencyversions.addAll(v);
        }else{
            this->dependencyversions.add(depvers);
        }
    }
    
    
    propertiesloaded=true;
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
