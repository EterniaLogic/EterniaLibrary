#ifndef MOUSE_HANDLE_EVENT_H_
#define MOUSE_HANDLE_EVENT_H_

enum MOUSEBUTTON {LEFT_BUTTON, MIDDLE_BUTTON, RIGHT_BUTTON, MIDDLE_BUTTON_UP,MIDDLE_BUTTON_DOWN};
enum MBEVENT {MOUSE_MOVE, MOUSE_CLICK, MOUSE_DOWN, MOUSE_UP, MOUSE_SCROLL_UP, MOUSE_SCROLL_DOWN};

// Data container for handle mouse events, initializer just fills in the variables
class MouseHandleEvent {
    public:
        MouseHandleEvent(MOUSEBUTTON button, MBEVENT type, int x, int y);
        virtual ~MouseHandleEvent();

        // public variables
        int x, y; // mouse location
        MOUSEBUTTON event_button; // button that caused this event
        MBEVENT event_type; // type of event
};

#endif
