#ifndef AIMON_H_
#define AIMON_H_

#include "../Data/includes.h"

// The AI Monarch is the consciousness for an AI.
// It controls and retrieves information from all of the subconscious AI nodes.
// The AI Monarch cannot actually do anything unless the subconscious AI nodes do it for it, as a monarch should not be required to do anything theirselves.

// The human consciousness can only hold between 3-7 things at the same time in short-term memory.

//    Monarch (Not conscious of the machine learning cloud, but is wise due to it)
//                                    |
//     [ML Factory                                                                                           ] 
//      |                |        |          |             |                  |                           |
//  memory_LSTM     ???_LSTM   ???_RNN    Vision_CNN   Motion_RNN    subroutine[preprogrammed]    Create-Delete_LSTM


class AIMonarch{
public:
    AIMonarch(){}
    
    LinkedList<CharString> ShortTermMemory; // STM changed by AI Node cloud
    
    bool decide(int stm_item); // ??? AI Monarch decides to do something based on STM Item
};


#endif
