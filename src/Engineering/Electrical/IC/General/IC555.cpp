//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
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
    setPins(new LinkedList<Pin>()); // set the pins list
}

IC555::~IC555() {
    setPins(0x0);
}

// operate the component
void IC555::tick(SecondTick* tickTime) {

}

// get the pin value
double IC555::getPin(int pin) {

}

// Set the pin value
void IC555::setPin(int pin, double value) {

}
