#ifndef KEY_HANDLE_EVENT_H_
#define KEY_HANDLE_EVENT_H_

enum KEYEVENT {KEY_DOWN, KEY_UP};

// Data container for handle mouse events, initializer just fills in the variables
class KeyHandleEvent {
    public:
        KeyHandleEvent(KEYEVENT event, unsigned char key, int modkey, int x, int y);
        virtual ~KeyHandleEvent();

        // public variables
        bool special; // special key?
        unsigned char key;
        KEYEVENT event_type; // type of event
        int x, y, modifier;
};

#endif
