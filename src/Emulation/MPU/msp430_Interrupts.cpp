//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "msp430.h"



// handle interrupts (aka: set address from vector bytes)
void MSP430::handleInterrupt(INTERRUPT_ID id){
    // use if/else instead of switch/case to emulate priority
    // (Switch/case would avoid a linear priority role)
    if(id == IID_RESET){                        // RESET
        setWord(PC, getWord(RESET_VECTOR));
    } else if(id == IID_OSC_MEM_FAULT){         // OSC Fault
        setWord(PC, getWord(NMI_VECTOR));
    } else if(id == IID_TA1_A0){                // TimerA1, A0
        setWord(PC, getWord(TIMER1_A0_VECTOR));
    } else if(id == IID_TA1_A1){                // TimerA1, A1
        setWord(PC, getWord(TIMER1_A1_VECTOR));
    } else if(id == IID_COMPARATOR_A){          // Comparator A
        setWord(PC, getWord(COMPARATORA_VECTOR));
    } else if(id == IID_WDT){                   // Watchdog timer
        setWord(PC, getWord(WDT_VECTOR));
    } else if(id == IID_TA0_A0){                // TimerA0, A0
        setWord(PC, getWord(TIMER0_A0_VECTOR));
    } else if(id == IID_TA0_A1){                // TimerA0, A1
        setWord(PC, getWord(TIMER0_A1_VECTOR));
    } else if(id == IID_USCI_RECEIVE){          // USCI Receive
        setWord(PC, getWord(USCIAB0RX_VECTOR));
    } else if(id == IID_USCI_TRANSMIT){         // USCI Transmit
        setWord(PC, getWord(USCIAB0TX_VECTOR));
    } else if(id == IID_ADC10){                 // ADC10
        setWord(PC, getWord(ADC10_VECTOR));
    } else if(id == IID_PORT2){                 // PORT 2 interrupts
        setWord(PC, getWord(PORT2_VECTOR));
    } else if(id == IID_PORT1){                 // Port 1
        setWord(PC, getWord(PORT1_VECTOR));
    }
}
