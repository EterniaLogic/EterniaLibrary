#ifndef CHATMANAGER_H_
#define CHATMANAGER_H_

#include "../../../Math/struct/vertex.h"

// The ChatServer can run either in-line with another TCP server or standalone.
// One of the major goals for the chat server is to allow chat messages to be distributed
//  between the clients based on either location in-game or a specific world-chat.

// P2P features might be useful here.


// VOIP Quality for this manager
enum VOIPQuality {VQ_8k, VQ_22k, VQ_48k}; // Voice quality sample rates


class ChatManager {
    public:
        ChatManager();

        // determine the distance for Local chat, VOIP, ect.


        // Manage audio, downsample, ect.
};

#endif
