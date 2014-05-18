#include "CLKProvider.h" 

CLKModule::CLKModule(int freq){
    frequency = freq;
}

// figure out if the tick timing is corresponding to
//      a certain frequency division.
void CLKModule::tick(){
    // use determined time dispersal to find out if this tick is correct
    //  
}

// Time dispersal is used to determine the number
// of seconds per clock.
void CLKModule::setTimeDispersal(int time){
    
}



CLKProvider::CLKProvider(){
    CLKList = new LinkedList<CLKModule>();
}

void CLKProvider::setFrequencyEvent(int frequency, void (function)()){
    
}
    

void CLKProvider::tick(){
    // loop through the clock list
}