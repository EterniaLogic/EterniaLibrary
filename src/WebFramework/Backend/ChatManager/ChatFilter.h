#ifndef CHAT_FILTER_H_
#define CHAT_FILTER_H_

#include "../../../Serialization/SpecificSerializer.h"

// The Chat Filter is a client-side filter.

//  It should include:
//      Anti-spam
//      Mute Others
//      Word Filter

class ChatFilter : public SpecificSerializer {
        ChatFilter();
};


#endif
