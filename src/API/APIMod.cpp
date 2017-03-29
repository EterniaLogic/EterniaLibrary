#include "APIMod.h"

APIMod::APIMod(CharString file, CharString name, CharString language, CharString version){
    this->file = file;
    this->name = name;
    this->language = language;
    this->version = version;
    permscope = P_MOD;
}

APIMod::APIMod(){
    permscope = P_MOD;
}

APIMod::~APIMod(){

}

void APIMod::init(CharString file, CharString name, CharString language, CharString version){
    this->file = file;
    this->name = name;
    this->language = language;
    this->version = version;
}




// API language implementation functions.
void APIMod::onLoad(){

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
