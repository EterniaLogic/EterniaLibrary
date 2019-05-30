#include "../APICore.h"
#include "../APIMod.h"
#include "../APIUser.h"

// Core
void testAPICore(); // creates a basic core and tests the folder locations and proper setup.
void testAPICoreLoadMods(); // loads all mods in a folder (only folder-type since zip/rar is not defined right now)
void testAPICoreEvents(); // test all event types (Also tests speed of multi-threading for mod permission events)
void testAPICorePermissions(); // makes sure that all permissions are set properly
void testAPIModRestrictions(); // tests to make sure that mods can only do certain actions if restricted with permissions.

// Mods
void testAPIModLoadFolder(); // load a single mod folder
void testAPIModDependencies(); // looks through all mod dependencies and makes sure that all dependencies are connected properly
void testAPIModPermissions(); // make sure a mod can 

void testAPIModUpdate(); // test a mod updating itself via Github or other online site. (Mod must have permission to use the internet?)

// User
void testAPIUser();
void testAPIUserPermissions(); // set a user's permissions and determines if they can use them for tasks
void testAPIUserPermissionScope(); // make sure a normal user cannot perform Administrative/Mod-specific tasks
