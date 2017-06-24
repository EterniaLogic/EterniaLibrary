#ifndef AUDIOBUF_
#define AUDIOBUF_

#include "../Data/Queue.h"

// Audio Buffers tell bitrates, stream data rates.
template<class T>
class AudioBuffer{
private:
    Queue buffer;
    int rate;

public:
    AudioBuffer(int bitrate);
    
    void add(T value); // add a value to the buffer
    T get(); // Grab a value from the buffer
    
    LinkedList<T> get(int number); // grab a list from the buffer
    
    int getBitrate();
};

#endif
