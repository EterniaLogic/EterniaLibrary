#include "IC555.h"

// pins:
// 1 GND
// 2 TRIG
// 3 OUT
// 4 RESET
// 5 CTRL
// 6 THR
// 7 DIS
// 8 Vcc

// f = 1.44/((R1+2*R2)*C)

IC555::IC555() {

}

IC555::~IC555() {

}

// operate the component
void IC555::tick(SecondTick* tickTime) {

}
