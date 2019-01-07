#include "Pin.h"

Pin::Pin(CharString PinName, PowerValue value) {
    name = PinName;
    val = value;
}

Pin::~Pin() {}
