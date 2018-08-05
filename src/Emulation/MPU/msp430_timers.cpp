


#include "msp430.h"




// checks the T0A0 flags and sets T0A0 interrupt flag to true
void MSP430::runTimer0(bool is_mclk) {
    // Queue local variables to save operations
    unsigned int TA0CTL_ = _m16(TA0CTL);
    unsigned int TA0CCTL0_ = _m16(TA0CCTL0);
    unsigned int TA0CCTL1_ = _m16(TA0CCTL1);
    unsigned int TA0CCTL2_ = _m16(TA0CCTL2);
    unsigned int TA0CCR0_ = _m16(TA0CCR0);
    unsigned int TA0CCR1_ = _m16(TA0CCR1);
    unsigned int TA0CCR2_ = _m16(TA0CCR2);
    unsigned int TA0R_ = _m16(TA0R);

    int clkSelect = (TA0CTL_ & 0x50|0x60) >> 8;
    // test for mclk or smclk (based on input bool variable)
    // test using TASSELx
    if((is_mclk  && (clkSelect==0)) || // TACLK == mclk
            (!is_mclk && (clkSelect==2))    ) { // SMCLK

        // if IDx bit set, Divide by 2^n (1/2/4/8)
        int clkDiv = (TA0CTL_ & 0x30|0x40) >> 6;
        const int MCx = (TA0CTL_ & 0x10|0x20) >> 4;

        // Test for MCx >= 1 (1 for 0->TACCR0, 2 for 0->0FFFF, 3 for 0->TACCR0->0)
        if(MCx > 0) {
            switch(MCx) {
                case 1:
                    // up to TACCR0 mode
                    TA0R_ = (TA0R_ >= TA0CCR0_) ? 0 : TA0R_+1;
                    _setTo16Value1(TA0R, TA0R_);
                    break;
                case 2:
                    // up to 0xffff (continuous) mode
                    TA0R_ = (TA0R_ >= 0xFFFF) ? 0 : TA0R_+1;
                    _setTo16Value1(TA0R, TA0R_);
                    break;
                case 3:
                    // up/down mode
                    TA0R_ = (T0_up) ? TA0R_+1 : TA0R_-1;
                    _setTo16Value1(TA0R, TA0R_);
                    T0_up = (TA0R_ >= TA0CCR0_ || TA0R_ <= 0) ? ~T0_up : T0_up;
                    break;
            }

            // test A0 CCR0 (Basic set)
            // test capture or compare
            if(!(TA0CCTL0_ & CAP)) { // compare mode
                // if compare, just compare TACCR0 with TA0R
                if(TA0R_ >= TACCR0_) {
                    // interrupt enabled?
                    if(TA0CCTL0_ & CCIE) {
                        TA0CCTL0_ |= CCIFG; // interrupt!
                    }

                    // Output pins:
                    // TA0.0 p1.1, p1.5
                    // TA0.1
                    // TA0.2

                    // if Output Mode (OUTMODx) is used
                    // if OUTMODx == 00, then OUT is used instead of timer output...
                    switch((TA0CCTL0_ & 0x20|0x30|0x40) >> 5) {
                        case 0:
                            _m(P1OUT) = TA0CCTL0_ & OUT; // direct output mode (follower)
                            break;
                        case 1:
                            _m(P1OUT) |= BIT5; // set
                            break;
                        case 2:
                            _m(P1OUT) ^= BIT5; // toggle on TACCRx / reset on TACCR0
                            break;
                        case 3:
                            _m(P1OUT) ^= BIT5; // set on TACCRx / reset on TACCR0
                            break;
                        case 4:
                            _m(P1OUT) ^= BIT5; // toggle
                            break;
                        case 5:
                            _m(P1OUT) &= ~BIT5; // reset
                            break;
                        case 6:
                            _m(P1OUT) ^= ~BIT5; // toggle on TACCRx / set on TACCR0
                            break;
                        case 7:
                            _m(P1OUT) ^= ~BIT5; // toggle on TACCRx / set on TACCR0
                            break;
                    }
                }
            } else {
                // capture mode
            }


            // test A1 CCR1

            // test A3 CCR2
        }
    }
}


void MSP430::runTimer1(bool is_mclk) {   }
