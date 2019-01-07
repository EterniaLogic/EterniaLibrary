#ifndef IANIMATED_OBJECT_H_
#define IANIMATED_OBJECT_H_

// Animated objects have frames, an FPS and a specific frame rate.


class IAnimated{
public:
    IAnimated();
    virtual ~IAnimated();
    // Possibly also implement frame-skipping?
    int frameFps, maxFrames, currentFrame;
    long timepassed;
    
    virtual void animateTick(long timeMillis); // time to go for in milliseconds. (FPS, ect. is figured out in implementations)
};

#endif
