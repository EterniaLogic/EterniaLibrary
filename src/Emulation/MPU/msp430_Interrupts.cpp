

#include "msp430.h"

namespace MSP430{
    // tests for all interrupts
    // only runs off of IFG bits
    void MSP430::testInterrupts() {
        //test for RESET
    }


    // handle interrupts (aka: set address from vector bytes)
    void MSP430::handleInterrupt(INTERRUPT_ID id) {
        switch(id) {
            case IID_RESET:                        // RESET
                setWord(PC, getWord(RESET_VECTOR));
                break;
            case IID_OSC_MEM_FAULT:         // OSC Fault
                setWord(PC, getWord(NMI_VECTOR));
                break;
            case IID_TA1_A0:                // TimerA1, A0
                setWord(PC, getWord(TIMER1_A0_VECTOR));
                break;
            case IID_TA1_A1:                // TimerA1, A1
                setWord(PC, getWord(TIMER1_A1_VECTOR));
                break;
            case IID_COMPARATOR_A:          // Comparator A
                setWord(PC, getWord(COMPARATORA_VECTOR));
                break;
            case IID_WDT:                   // Watchdog timer
                setWord(PC, getWord(WDT_VECTOR));
                break;
            case IID_TA0_A0:                // TimerA0, A0
                setWord(PC, getWord(TIMER0_A0_VECTOR));
                break;
            case IID_TA0_A1:                // TimerA0, A1
                setWord(PC, getWord(TIMER0_A1_VECTOR));
                break;
            case IID_USCI_RECEIVE:          // USCI Receive
                setWord(PC, getWord(USCIAB0RX_VECTOR));
                break;
            case IID_USCI_TRANSMIT:         // USCI Transmit
                setWord(PC, getWord(USCIAB0TX_VECTOR));
                break;
            case IID_ADC10:                 // ADC10
                setWord(PC, getWord(ADC10_VECTOR));
                break;
            case IID_PORT2:                 // PORT 2 interrupts
                setWord(PC, getWord(PORT2_VECTOR));
                break;
            case IID_PORT1:                 // Port 1
                setWord(PC, getWord(PORT1_VECTOR));
        }
    }
}
