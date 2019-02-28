
#include "RAM.h"

// initializes [Memory] sized ram in bytes
// [Memory] = 2^IO
RAM::RAM(long IO) {
    pins.add(new Pin("GND", PowerValue(0,0)));

    for(int i=0; i<IO; i++) {
        CharString dValue = "Addr-";
        dValue.concata(CharString::ConvertFromInt(i));
        pins.add(new Pin(dValue, PowerValue(0,0)));
    }

    for(int i=0; i<IO; i++) {
        CharString dValue = "Data-";
        dValue.concata(CharString::ConvertFromInt(i));
        pins.add(new Pin(dValue, PowerValue(0,0)));
    }

    pins.add(new Pin("Vcc", PowerValue(0,0)));
    pins.add(new Pin("CLK", PowerValue(0,0)));
}

RAM::~RAM() {

}
