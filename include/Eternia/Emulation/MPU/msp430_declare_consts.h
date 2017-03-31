//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------


#ifndef MSP430_DECLAREVARS_H_
#define MSP430_DECLAREVARS_H_

// this file forcibly declares variables that are used by default
//      in the MSP430.
// Any variable that uses SFR_8BIT or SFR_16BIT has to be
//      declared by the compiler.



// bytes
#define IE1             0x0
#define IFG1            0x1
#define IE2             0x2
#define IFG2            0x3

// bytes
#define ADC10DTC0       0x48
#define ADC10DTC1       0x49
#define ADC10AE0        0x50
// WORDS
#define ADC10CTL0       0x1b0
#define ADC10CTL1       0x1b2
#define ADC10MEM        0x1b4
#define ADC10SA         0x1bc

// bytes
#define DCOCTL          0x56                               // DCO Clock Frequency Control
#define BCSCTL1         0x57                            // Basic Clock System Control 1
#define BCSCTL2         0x58                            // Basic Clock System Control 2
#define BCSCTL3         0x53                            // Basic Clock System Control 3


// WORDS
#define CACTL1          0x59                             // Comparator A Control 1
#define CACTL2          0x5a                             // Comparator A Control 2
// byte
#define CAPD            0x5b                               // Comparator A Port Disable

// WORDS
#define FCTL1           0x128                             // FLASH Control 1
#define FCTL2           0x12a                             // FLASH Control 2
#define FCTL3           0x12c                             // FLASH Control 3

// bytes
#define P1IN            0x20                               // Port 1 Input
#define P1OUT           0x21                              // Port 1 Output
#define P1DIR           0x22                              // Port 1 Direction
#define P1IFG           0x23                              // Port 1 Interrupt Flag
#define P1IES           0x24                              // Port 1 Interrupt Edge Select
#define P1IE            0x25                               // Port 1 Interrupt Enable
#define P1SEL           0x26                              // Port 1 Selection
#define P1SEL2          0x41                             // Port 1 Selection 2
#define P1REN           0x27                              // Port 1 Resistor Enable

// bytes
#define P2IN            0x28                               // Port 2 Input
#define P2OUT           0x29                              // Port 2 Output
#define P2DIR           0x2a                              // Port 2 Direction
#define P2IFG           0x2b                              // Port 2 Interrupt Flag
#define P2IES           0x2c                              // Port 2 Interrupt Edge Select
#define P2IE            0x2d                               // Port 2 Interrupt Enable
#define P2SEL           0x2e                              // Port 2 Selection
#define P2SEL2          0x42                             // Port 2 Selection 2
#define P2REN           0x2f                              // Port 2 Resistor Enable


/*P3IN    0x                               // Port 3 Input
P3OUT    0x                              // Port 3 Output
P3DIR    0x                              // Port 3 Direction
P3SEL    0x                              // Port 3 Selection
P3SEL2    0x                             // Port 3 Selection 2
P3REN    0x                              // Port 3 Resistor Enable
*/

#define TA0IV           0x12e     // Word                        // Timer0_A3 Interrupt Vector Word   /
#define TA0CTL          0x160    // Word                        // Timer0_A3 Control
#define TA0CCTL0        0x162  // Word                        // Timer0_A3 Capture/Compare Control 0
#define TA0CCTL1        0x164  // Word                        // Timer0_A3 Capture/Compare Control 1
#define TA0CCTL2        0x166  // Word                        // Timer0_A3 Capture/Compare Control 2
#define TA0R            0x170      // Word                        // Timer0_A3
#define TA0CCR0         0x172   // Word                        // Timer0_A3 Capture/Compare 0
#define TA0CCR1         0x174   // Word                        // Timer0_A3 Capture/Compare 1
#define TA0CCR2         0x176   // Word                        // Timer0_A3 Capture/Compare 2



#define TA1IV           0x11e        // Word                     // Timer1_A3 Interrupt Vector Word
#define TA1CTL          0x180       // Word                     // Timer1_A3 Control
#define TA1CCTL0        0x182     // Word                     // Timer1_A3 Capture/Compare Control 0
#define TA1CCTL1        0x184     // Word                     // Timer1_A3 Capture/Compare Control 1
#define TA1CCTL2        0x186     // Word                     // Timer1_A3 Capture/Compare Control 2
#define TA1R            0x190         // Word                     // Timer1_A3
#define TA1CCR0         0x192      // Word                     // Timer1_A3 Capture/Compare 0
#define TA1CCR1         0x194      // Word                     // Timer1_A3 Capture/Compare 1
#define TA1CCR2         0x196      // Word                     // Timer1_A3 Capture/Compare 2


#define UCA0CTL0        0x60                           // USCI A0 Control Register 0
#define UCA0CTL1        0x61                           // USCI A0 Control Register 1
#define UCA0BR0         0x62                            // USCI A0 Baud Rate 0
#define UCA0BR1         0x63                            // USCI A0 Baud Rate 1
#define UCA0MCTL        0x64                           // USCI A0 Modulation Control
#define UCA0STAT        0x65                           // USCI A0 Status Register
#define UCA0RXBUF       0x66                          // USCI A0 Receive Buffer
#define UCA0TXBUF       0x67                          // USCI A0 Transmit Buffer
#define UCA0ABCTL       0x5d                          // USCI A0 LIN Control
#define UCA0IRTCTL      0x5e                         // USCI A0 IrDA Transmit Control
#define UCA0IRRCTL      0x5f                         // USCI A0 IrDA Receive Control



#define UCB0CTL0        0x68                           // USCI B0 Control Register 0
#define UCB0CTL1        0x69                           // USCI B0 Control Register 1
#define UCB0BR0         0x6a                            // USCI B0 Baud Rate 0
#define UCB0BR1         0x6b                            // USCI B0 Baud Rate 1
#define UCB0I2CIE       0x6c                          // USCI B0 I2C Interrupt Enable Register
#define UCB0STAT        0x6d                           // USCI B0 Status Register
#define UCB0RXBUF       0x6e                          // USCI B0 Receive Buffer
#define UCB0TXBUF       0x6f                          // USCI B0 Transmit Buffer
#define UCB0I2COA       0x118    //Word                     // USCI B0 I2C Own Address
#define UCB0I2CSA       0x11a    //Word                     // USCI B0 I2C Slave Address



#define WDTCTL          0x120

// bytes
#define CALDCO_16MHZ    0x10f8                       // DCOCTL  Calibration Data for 16MHz
#define CALBC1_16MHZ    0x10f9                       // BCSCTL1 Calibration Data for 16MHz
#define CALDCO_12MHZ    0x10fa                       // DCOCTL  Calibration Data for 12MHz
#define CALBC1_12MHZ    0x10fb                       // BCSCTL1 Calibration Data for 12MHz
#define CALDCO_8MHZ     0x10fc                        // DCOCTL  Calibration Data for 8MHz
#define CALBC1_8MHZ     0x10fd                        // BCSCTL1 Calibration Data for 8MHz
#define CALDCO_1MHZ     0x10fe                        // DCOCTL  Calibration Data for 1MHz
#define CALBC1_1MHZ     0x10ff                        // BCSCTL1 Calibration Data for 1MHz

#define CAL1MHZ         0xff
#define CAL8MHZ         0xfe
#define CAL12MHZ        0xfd
#define CAL16MHZ        0xfc

#endif
