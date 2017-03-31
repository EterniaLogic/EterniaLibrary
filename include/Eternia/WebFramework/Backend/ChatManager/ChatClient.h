#ifndef CHATCLIENT_H_
#define CHATCLIENT_H_

#include "ChatChannel.h"

// The Chat Client is a limited client that may be tied to a specific chat channel,
//  global or planet area.

class ChatClient {
    public:
        ChatClient();

        CharString tag, name;
        ChatChannel *currentChannel;

//        void (*receiveMessage)(ChatClient* client, CharString message);

        // send message to all in the channel, based on channel rules
        void sendMessage(CharString text);
        void recvMessage(ChatClient* client, CharString text);
        
        // Audio stream (Data proxy)
        
        void ban(ChatChannel* channel); // ban from specific channel
        void tempBan(ChatChannel* channel, long ms); // temp ban from specific channel
        void mute(ChatChannel* channel, long ms); // mute on channel for set time in milliseconds
};


#endif
