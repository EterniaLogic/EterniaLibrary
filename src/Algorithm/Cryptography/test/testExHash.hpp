#ifndef TESTEXHASH_H_
#define TESTEXHASH_H_

#include <iostream>
#include <stdlib.h>
#include "../../../MiscLib/CharString.h"
#include "../ExHash.h"
using namespace std;


// Tests the ExHash algorithm for collisions
void testExHash(){
    // uint64_t exSumMap(CharString *str, uint64_t maxVal, int steps)
    CharString* str = new CharString();

    int numDigitPlaces = 10; // Number of digit values to go up to.
    const unsigned int MapSize = 400000; // Standard map size up to 64k values
    int calculated = 0; // calculated value on the map
    int collisions = 0; // collision counter

    uint64_t mapx[MapSize];
    char strc[numDigitPlaces];

    // Set the default value to a number that "should" be impossible
    for(int i=0;i<MapSize;i++){
        mapx[i] = 0;

    }

    // initialize the char
    for(int i=0;i<numDigitPlaces;i++){
        strc[i] = 0;
    }




    //
    for(int i=1;i<=2;i++){
        // Generate direct values from 0x00 to 0xFF (0 to 255)
        for(int j=0;j<255;j++){
            strc[i-1] = j;
            str->set(strc, i+1);

            calculated = exSumMap(str, MapSize, 1);
            if(mapx[calculated] != 0){
                collisions++;
                cout << "Collision @ " << calculated << " with " << strc << endl;
            }
            else mapx[calculated] = 1;
        }
    }

    char *result;
    if(collisions > 10) result = "Failed";
    else "Passed";
    cout << "[Test ExHash] Collisions: " << collisions << " " << result << endl;
}

#endif
