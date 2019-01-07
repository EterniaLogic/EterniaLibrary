#include "MouseHandleEvent.h"

// Initialize
MouseHandleEvent::MouseHandleEvent(MOUSEBUTTON button, MBEVENT type, int _x, int _y) {
    event_button = button;
    event_type = type;
    x = _x;
    y = _y;
}

// Dispose
MouseHandleEvent::~MouseHandleEvent() {

}
