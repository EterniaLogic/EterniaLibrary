#ifndef TESTEXHASH_H_
#define TESTEXHASH_H_

#include <iostream>
#include <stdlib.h>
#include "../../../Data/CharString.h"
#include "../ExHash.h"
using namespace std;


// Tests the ExHash algorithm for collisions
void testExHash() {
    // uint64_t exSumMap(CharString *str, uint64_t maxVal, int steps)
    CharString* str = new CharString();

    const int numDigitPlaces = 2; // Number of digit values to go up to.
    const int MapSize = numDigitPlaces*256; // Standard map size up to 64k values
    unsigned int calculated = 0; // calculated value on the map
    int collisions = 0; // collision counter
    int overflow = 0; // number greater than mapsize

    bool mapx[MapSize];
    char strc[numDigitPlaces];

    // Set the default value to a number that "should" be impossible
    for(uint64_t i=0; i<MapSize; i++) mapx[i] = 0;

    // initialize the char
    for(int i=0; i<numDigitPlaces; i++) strc[i] = 0;

    //
    for(int i=1; i<=numDigitPlaces; i++) {
        // Generate direct values from 0x00 to 0xFF (0 to 255)
        for(int j=0; j<255; j++) {
            strc[i-1] = j;
            str->set(strc, i+1);
            calculated = exSumMap<unsigned int>(str, MapSize, 1);
            
            if(calculated > MapSize){
                overflow++;
                cout << "Overflow!" << endl;
                continue;
            }
            
            if(mapx[calculated]) {
                collisions++;
                printf("Collision @ %d with (%d, %d)\n", calculated, i, j);
            } else mapx[calculated] = true;
        }
    }

    char *result;
    float percent = 100.f*(collisions)/(numDigitPlaces*256.0f);
    if(percent > 5) result = "Failed";
    else "Passed";
    
    cout << "[Test ExHash] Collisions: " << collisions << " ("<<percent<<"% collided) " << result << " ::: Overflows: " << overflow << endl;
}

#endif
