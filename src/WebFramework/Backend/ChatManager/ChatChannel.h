#ifndef CHATCHANNEL_H_
#define CHATCHANNEL_H_

#include "../../../Design/Colors.h"

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


        // Server-side only
        bool muted; // is this person muted to chat here?
        bool moderator; // is this person a moderator?
};

#endif
