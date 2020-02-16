#include "Dwarves.h"


Dwarves::Dwarves(){
    instance=this;
    tevent=true;
    ttiles=true;
    tentities=true;
    tfps=true;
}

void Dwarves::onInit(){
    initraces(); // initialize races
}

void Dwarves::onEnable(){
    // doesn't matter
}

void Dwarves::onDisable(){
    // doesn't matter
}

void Dwarves::onUnload(){
    // on quit game
    // all of the mods were loaded before this.
}
