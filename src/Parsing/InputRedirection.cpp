

#include "InputRedirection.h"
using namespace std;
InputRedirection::InputRedirection() {
    stop = false;
}

InputRedirection::~InputRedirection() {
}

//void InputRedirection::handleInputLine(CharString* input){}

bool InputRedirection::process() {
    const int readlen = 5000;
    char* readt = new char[readlen]; // local test variable, used to help exit inf. loop

    // fill list with NULL zeroes. This clears list and prevents descrepancies.
    // these @s define the end of the pre-recorded list.
    for(int i=0; i<readlen; i++) readt[i] = 0x0;

    cin.getline(readt,readlen);
    CharString* Line = new CharString(readt);

    //if(!(Line->isEmpty()) && Line->getSize() > 1){ // is the line not empty? Is it longer then 1?
    handleInputLine(Line); // EXECUTE the line.
    //}else{
    //  return true;
    //}
    return false;
}

void InputRedirection::redirect() {
    while(!stop) { //we cannot measure the number of words coming in.
        cout << "#> ";
        if(process()) { // can we continue processing?
            break;
        }
    }
}
