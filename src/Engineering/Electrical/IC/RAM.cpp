
#include "RAM.h"

// initializes [Memory] sized ram in bytes
// [Memory] = 2^IO
RAM::RAM(long IO) {
    pins.add(new Pin(CharString("GND"), PowerValue(0,0)));

    for(int i=0; i<IO; i++) {
        CharString dValue = CharString("Addr-");
        dValue.concata(CharString::ConvertFromInt(i));
        pins.add(new Pin(dValue, PowerValue(0,0)));
    }

    for(int i=0; i<IO; i++) {
        CharString dValue = CharString("Data-");
        dValue.concata(CharString::ConvertFromInt(i));
        pins.add(new Pin(dValue, PowerValue(0,0)));
    }

    pins.add(new Pin(CharString("Vcc"), PowerValue(0,0)));
    pins.add(new Pin(CharString("CLK"), PowerValue(0,0)));
}

RAM::~RAM() {

}
