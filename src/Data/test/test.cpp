//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "test.h"

class TestStructure
{
    //int tileSet[100][100];
    public:
        TestStructure(){ 
            //for(int i=0;i<100;i++){
            //    for(int j=0;j<100;j++){
            //        tileSet[i][j] = i*j;
            //    }
            //}
        }
        
        int dataValue;
};

void testDataStructures(){
    long sampleSize = 1024*1024;

    cout << "test placement" << endl;
    char c[9];
    strcpy(c,"data.txt");
    FileCache <TestStructure> fileCache((char*)&c, (long)(sampleSize), true);
    char a[5];
    strcpy(a,"test");
    
    // set object to OUT
    long t1 = clock();
    for(long i=0;i<sampleSize;i++){
        TestStructure* ts = new TestStructure();
        ts->dataValue = i+1;
        int OUT = fileCache.add(ts);
    }
    long t2 = clock()-t1;
    cout << "SetTime = " << t2/CLOCKS_PER_SEC << endl;
    
    // test object from Get
    t1 = clock();
    for(long i=0;i<sampleSize;i++){
        TestStructure* ffs = fileCache.get(i);
        if(ffs->dataValue != i+1) {
            cout << "FileCache Error @ " << (i+1) << " Where: " << ffs->dataValue << endl;
        }
    }
    t2 = clock()-t1;
    cout << "GetTime = " << t2/CLOCKS_PER_SEC << endl;
    
    cout << "test done." << endl;
}
