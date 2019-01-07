


#include "msp430.h"


MSP430::MSP430() {
    init();
    paused = 0;
    // initialize interrupt handle lists using a hashmap
    interruptHandles = HashMap<LinkedList<InterruptHandle> >(20);
    for(int i=0; i<20; i++) {
        interruptHandles.addL(0UL, LinkedList<InterruptHandle>());
    }
}

void MSP430::init() {
    // clear out memory
    for(int i=0; i<MEM_SIZE; i++) {
        _mem(i) = 0; // _mem(a) = Memory[a]
    }

    // value placeholders for cal data
    _mem(CALDCO_1MHZ) =  _mem(CALBC1_1MHZ) =    CAL1MHZ;
    _mem(CALDCO_8MHZ) =  _mem(CALBC1_8MHZ) =    CAL8MHZ;
    _mem(CALDCO_12MHZ) = _mem(CALBC1_12MHZ) =   CAL12MHZ;
    _mem(CALDCO_16MHZ) = _mem(CALBC1_16MHZ) =   CAL16MHZ;

    // Set default values
    // Default 1 MHz clock
    _mem(DCOCTL) = _mem(CALDCO_1MHZ);
    _mem(BCSCTL1) = _mem(CALBC1_1MHZ);

    // init vars
    smclk_cnt = 0;
    PC=0xC000; // Program Counter
    SP=0x0400; // Stack Pointer

    // reset all other vars
    SR=R3=R4=R5=R6=R7=R8=R9=R10=R11=R12=R13=R14=R15=0;
}

// handle master clock
void MSP430::mclk() {
    if(!paused) {
        // Handle smclk
        // get smclk division BCSCTL2 DIVSx
        char divs = (_m(BCSCTL2) & 0x6) >> 1;
        if(smclk_cnt >= divs) {
            smclk_cnt = 0;
            smclk(); // exe smclk
        } else smclk_cnt++;

        // Handle interrupts
        testInterrupts();

        // Handle timer countdowns
        runTimer0(1);
        runTimer1(1);

        // main loop
        PC++; // increment pc
        exec(PC); // execute line

        // non-msp430: Handle master timing (DCOCTL == CALDCO_1MHZ)?
        // BCSCTL2 DIVMx
        char divm = (_m(BCSCTL2) & 0x8|0x10) >> 4;
        char speed = _m(DCOCTL);
        int mdiv = CLOCKS_PER_SEC/(speed*1000000*divm);

        // sleep for time
        for(int i=0; i<mdiv; i++);
    }
}

// handle sub-master clock
void MSP430::smclk() {
    // Handle timer countdowns
    runTimer0(0);
    runTimer1(0);

    // handle Serial communications for A and B USCI ports
    handleUSCIA();
    handleUSCIB();
}

// execute an instruction
void MSP430::exec(unsigned int) {

}


// get a byte from the memory
// [address]
unsigned char MSP430::getByte(unsigned int address) {
    return _mem(address);
}

// get a word from the memory
// [address]<<4 +[address+1]
unsigned int MSP430::getWord(unsigned int address) {
    return _m16(address); //_mem(address)<<4 + _mem_2(address);
}

void MSP430::setByte(unsigned int address, unsigned char value) {
    _mem(address) = value;
}

void MSP430::setWord(unsigned int address, unsigned int value) {
    _setTo16Value1(address, value);
}

// sets ADC10MEM and sets ADC10IFG
void MSP430::setADC10Value(unsigned int value) {
    _mem(ADC10MEM) = value;
}

void MSP430::Pause() {
    paused = 1;
}
void MSP430::Continue() {
    paused = 0;
}
