//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "testDataStructures.h"

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

void testFileCache(){
    cout << "FileCache => ";
    long sampleSize = 1024;
    long errors = 0;
    char c[9];
    strcpy(c,"data.txt");
    FileCache <TestStructure> fileCache((char*)&c, (long)(sampleSize), true);
    char a[5];
    strcpy(a,"test");
    int intmax = 32765;
    // set object to OUT
    long t1 = clock();
    for(long i=0;i<intmax*2;i++){
        TestStructure* ts = new TestStructure();
        ts->dataValue = i+1;
        int OUT = fileCache.add(ts);
    }
    long t2 = clock()-t1;

    // test object from Get
    t1 = clock();

    for(long i=0;i<intmax*2;i++){
        TestStructure* ffs = fileCache.get(i);
        if(ffs->dataValue != i+1) {
            errors++;
        }
    }
    t2 = clock()-t1;

    if(errors == 0){
      cout << "Pass" << endl;
    }else{
      cout << "FAIL" << endl;
    }
    fileCache.clean();
}

void testBitMap(){
  cout << "BitMap => ";
  BitMap* cc = new BitMap(1024,768); // suggested size: 59 mb
  //cout << "Size: " << (cc->width*cc->height*sizeof(bmbit))/1024/1024 << endl;

  // change every single value
  for(int i=0;i<cc->width;i++){
    for(int j=0;j<cc->height;j++){
      //cout << i << ", " << j << endl;
      cc->map[j][i].r = 128;
      cc->map[j][i].g = 8;
      cc->map[j][i].b = 254;
      cc->map[j][i].a = 64;
    }
  }
  //cout << "changed" << endl;

  cc->~BitMap();

  cout << "Pass" << endl;
}

// tests the queue for ability.
void testQueue()
{
        cout << "Queue => ";
        Queue* q = new Queue();
        CharString* cc = new CharString("test@#$%^*()_+1234567890");
        q->enqueue(cc);
        CharString* qq = (CharString*)q->dequeue();
        if(qq == cc){
                cout << "Pass" << endl;
        } else{
                cout << "Fail" << "(" << qq->get() << ")" << endl;
        }
}

void testPriorityQueue()
{
     cout << "PriorityQueue => ";
        PriorityQueue* q = new PriorityQueue();
        CharString* cc = new CharString("test@#$%^*()_+1234567890",24);
        q->insert(0,cc);
        CharString* qq = (CharString*)q->removeMin();
        if(qq == cc){
                cout << "Pass" << endl;
        } else{
                cout << "Fail" << "(" << qq->get() << ")" << endl;
        }
}

void testDataStructures(){
    testFileCache();
    testBitMap();
    testQueue();
    //testPriorityQueue();

    cout << "Datastructures test Done" << endl;
}
