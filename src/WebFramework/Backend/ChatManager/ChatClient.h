#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include "ChatChannel.h"

// The Chat Client is a limited client that may be tied to a specific chat channel,
//  global or planet area.

class ChatClient{
public:
    ChatClient();
    
    CharString tag, name;
    
    void (*receiveMessage)(ChatClient* client, CharString* message);
    
    // send message to all in the channel, based on channel rules
    void sendMessage(CharString* text, ChatChannel* channel);
};


#endif
