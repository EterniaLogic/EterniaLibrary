#include "KeyHandleEvent.h"

// Initialize
KeyHandleEvent::KeyHandleEvent(KEYEVENT event, unsigned char _key, int _modkey, int _x, int _y) {
    event_type = event;
    this->key = _key;
    this->modifier = _modkey;
    special = false;
}

// Dispose
KeyHandleEvent::~KeyHandleEvent() {

}
