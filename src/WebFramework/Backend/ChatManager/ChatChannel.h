#ifndef CHATCHANNEL_H_
#define CHATCHANNEL_H_

#include "../../../Design/Colors.h"
#include "../../../Data/CharString.h"
#include "ChatClient.h"

// The Chat Channel
// This ChatChannel is player-specific

class ChatChannel {
    private:
        static LinkedList<ChatChannel> openChannels;

        char* name;
        vertex channelcolor;

        char* tag;
        vertex tagcolor;

        int chatspeed; // how often can somebody chat in this channel? (milliseconds)
    public:

        ChatChannel(char* name, vertex channelcolor, char* tag, vertex tagcolor, int chatspeed);

        void sendMessage(ChatClient* client, CharString message); // send a chat message on this channel
        void sendAudioBuffer(ChatClient* client, CharString buffer, int bitrate); // send a buffered audio value
};

#endif
