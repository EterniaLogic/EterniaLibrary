
#include "RAM.h"

// initializes [Memory] sized ram in bytes
// [Memory] = 2^IO
RAM::RAM(long IO) {
    pins -> add(new Pin(new CharString("GND"), new PowerValue(0,0)));

    for(int i=0; i<IO; i++) {
        CharString* dValue = new CharString("Addr-");
        dValue -> concata(CharString::ConvertFromInt(i));
        pins -> add(new Pin(dValue, new PowerValue(0,0)));
    }

    for(int i=0; i<IO; i++) {
        CharString* dValue = new CharString("Data-");
        dValue -> concata(CharString::ConvertFromInt(i));
        pins -> add(new Pin(dValue, new PowerValue(0,0)));
    }

    pins -> add(new Pin(new CharString("Vcc"), new PowerValue(0,0)));
    pins -> add(new Pin(new CharString("CLK"), new PowerValue(0,0)));
}

RAM::~RAM() {

}
