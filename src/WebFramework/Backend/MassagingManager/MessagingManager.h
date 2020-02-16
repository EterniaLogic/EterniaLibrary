#ifndef MessagingManager_H_
#define MessagingManager_H_

#include "../Backend.h"
#include "../../../Data/includes.h"


// The Messaging Manager helps bridge the gap between different servers by providing a channel to communicate.
//  The servers act in a peer-to-peer system, opening multiple ports.

class MessagingManager : public Backend{

public:
    MessagingManager();

    void subscribe(CharString channel); // I want to hear the chatter.
    void unsubscribe(CharString channel); // I am not listening to this channel anymore!
    
    LinkedList<CharString> receive(); // Blocking receive message(s).
    
    //      use    void receivefunc(LinkedList<Charstring> message){ ... }
    //  MM->receive(&receivefunc);
    void receive(void (*func)(LinkedList<CharString> message)); // Threaded receive message using &func
    
    void sendMessage(CharString channel, CharString message); // send info to this channel
};

#endif
