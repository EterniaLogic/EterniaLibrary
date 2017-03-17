#ifndef AUDIOBUF_
#define AUDIOBUF_

#include "../Data/Queue.h"

// Audio Buffers tell bitrates, stream data rates.
class AudioBuffer{
private:
    Queue buffer;
    int rate;

public:
    AudioBuffer(int bitrate);
    
    void add(float value);
    float get();
    
    int getBitrate();
};

#endif
