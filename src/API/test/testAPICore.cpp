#include "testAPI.h"

// creates a basic core and tests the folder locations and proper setup.
void testAPICore(){ 
    APICore* core = new APICore("testCore", "mods", "log.txt");
    core->Init();
}

// loads all mods in a folder (only folder-type since zip/rar is not defined right now)
void testAPICoreLoadMods(){

}

// test all event types (Also tests speed of multi-threading for mod permission events)
void testAPICoreEvents(){

} 

// makes sure that all permissions are set properly
void testAPICorePermissions(){

}

// tests to make sure that mods can only do certain actions if restricted with permissions.
void testAPIModRestrictions(){

}
