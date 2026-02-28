#ifndef TESTEXHASH_H_
#define TESTEXHASH_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "../../../src/Data/CharString.h"
#include "../../../src/Data/CyclicList.hpp"
#include "../../../src/Algorithm/Cryptography/ExSum.h"
#include "../../../src/Parsing/LoadFile.h"


// Tests the ExHash algorithm for collisions
void testExHash() {
    // uint64_t exSumMap(CharString *str, uint64_t maxVal, int steps)
    CharString* str = new CharString();

    const uint64_t numDigitPlaces = 3; // Number of digit values to go up to.
    //const int MapSize = numDigitPlaces*256; // Standard map size up to 64k values
    const uint64_t testSize = (uint64_t)pow(2.0f,numDigitPlaces*(8.0f-1));
    const uint64_t theoSize = (uint64_t)pow(2.0f,numDigitPlaces*(8.0f));
    int MapSize = pow(2,14); // Standard map size up to 64k values
    unsigned long calculated = 0; // calculated value on the map
    int collisions = 0; // collision counter
    int overflow = 0; // number greater than mapsize

    cout << "[Test ExHash] Map Size: " << MapSize << " -- testing "<< testSize << " values" << endl; cout.flush();
    long long actualtested=0;
    int mapx[MapSize]; // map collision detect
    char strc[numDigitPlaces];
    unsigned char c;
    bool skip=false;
    long double basetime, totalTime;
    int sh=0, mask=0,j=0;
    CyclicList<double> *cyclecalc = new CyclicList<double>(10000);

    // Set the default value to a number that "should" be impossible
    for(int i=0; i<MapSize; i++) mapx[i] = 0;

    // initialize the char
    


    // 000 -> 001 .... 014 ---> 015 etc.
    
    for(uint64_t i=0;i<theoSize;i++){
        for(int i=0; i<numDigitPlaces; i++) strc[i] = 0; // reclear
        skip=false;
        
        //CharString* str =CharString::ConvertFromLong(i); // no?
        for(j=0; j<numDigitPlaces; j++){
            sh = 2*j; // shift value
            mask = 255<<sh; // mask to select character
            uint8_t c = (uint8_t)((mask & i) >> sh);
            if(c >= 128) {skip=true;break;}
            strc[j] = (char)c;
            //cout << j << "=" << (int)((mask & i) >> sh) << " ";
        }
        //cout << endl;
        if(skip) continue;
        
        str->set(strc, numDigitPlaces);
        //cout << "[Test ExHash] " << i << " '" << strc << "'  =>  ";cout.flush();// << endl;
        
        // perform test
        basetime = ((long double)clock()/CLOCKS_PER_SEC);
        calculated = exSumMap<unsigned long>(str, MapSize, 1);
        totalTime = ((long double)clock()/CLOCKS_PER_SEC) - basetime;
        cyclecalc->add(totalTime);
        //cout << "test time: " << totalTime*1000000 << " Nanoseconds" << endl;
        
        
        actualtested++;    
        //cout << calculated << endl; cout.flush();
        
        if(calculated > MapSize){
            overflow++;
            //cout << "Oversize! value=" << calculated << endl;
            continue;
        }
        
        if(mapx[calculated]>0) {
            collisions++;
            printf("Collision @ %d with (%d)\n", calculated, i);
        }
        mapx[calculated] ++; 
        
        
        
    }



    // loop through all character possibilities for numDigitPlaces
    /*for(unsigned char j=0; j<128; j++) { // Generate direct values from 0x00 to 0xFF (0 to 255)
        //if(j%10==0) cout << j << endl;
        cout << (int)j << endl;
        for(int i=1; i<=numDigitPlaces; i++) {
            actualtested++;
            cout << "[Test ExHash] " << i << ", " << (unsigned int)j << "  =>  ";// << endl;
            cout.flush();
            strc[i-1] = (char)j;
            str->set(strc, i+1);
            calculated = exSumMap<unsigned int>(str, MapSize, 6);
            
            cout << calculated << endl; cout.flush();
            
            if(calculated > MapSize){
                overflow++;
                cout << "Oversize! value=" << calculated << endl;
                continue;
            }
            
            if(mapx[calculated]) {
                collisions++;
                printf("Collision @ %d with (%d, %d)\n", calculated, i, j);
            } else mapx[calculated] = true;
        }
    }*/
    //cout << "[Test ExHash] done" << endl;
    CharString result="";
    float percent = 100.f*(collisions)/(actualtested);
    if(percent > 5) result = "Failed";
    else result = "Passed";
    cout << "[Test ExHash] Average time: " << cyclecalc->getAverage()*1000000 << " nanoseconds" << endl;
    cout << "[Test ExHash] Map Size: " << MapSize << " -- tested " << actualtested << " of " << testSize << " possible values" << endl; cout.flush();
    cout << "[Test ExHash] Collisions: " << collisions << " ("<<percent<<"% collided) '" << result.get() << "' ::: Oversized: " << overflow << endl;
    
    // print to file for distribution review
    ofstream infile;
    infile.open("/tmp/distribution.csv",ios::trunc);
    for(int i=0; i<MapSize; i++){
        infile << i << "\t" << mapx[i] << endl;
    }
    infile.close();
    
}

#endif
