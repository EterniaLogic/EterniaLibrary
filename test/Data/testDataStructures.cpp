

#include "testDataStructures.h"

class TestStructure {
        //int tileSet[100][100];
    public:
        TestStructure() {
            //for(int i=0;i<100;i++){
            //    for(int j=0;j<100;j++){
            //        tileSet[i][j] = i*j;
            //    }
            //}
        }

        int dataValue;
};

void testFileCache() {
    cout << "FileCache => ";
    
    /*
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
    for(long i=0; i<sampleSize; i++) {
        TestStructure* ts = new TestStructure();
        ts->dataValue = i+2;
        int OUT = fileCache.add(ts);
    }
    long t2 = clock()-t1;

    // test object from Get
    t1 = clock();

    for(long int i=0; i<sampleSize; i++) {
        TestStructure* ffs = fileCache.get(i);
        if(ffs == 0x0 || ffs->dataValue != i+2) {
            errors++;
        }
    }
    t2 = clock()-t1;

    if(errors == 0) {
        cout << "Pass" << endl;
    } else {
        cout << "FAIL errors:" << errors << endl;
    }
    //fileCache.clean();
    */
}

void testBitMap() {
    cout << "BitMap => ";
    BitMap* cc = new BitMap(1024,768); // suggested size: 59 mb
    //cout << "Size: " << (cc->width*cc->height*sizeof(bmbit))/1024/1024 << endl;

    // change every single value
    for(int i=0; i<cc->width; i++) {
        for(int j=0; j<cc->height; j++) {
            //cout << i << ", " << j << endl;
            cc->map[i][j].r = 128;
            cc->map[i][j].g = 8;
            cc->map[i][j].b = 254;
            cc->map[i][j].a = 64;
        }
    }
    //cout << "changed" << endl;

    cc->~BitMap();

    cout << "Pass" << endl;
}

// tests the queue for ability.
void testQueue() {
    cout << "Queue => ";
    Queue* q = new Queue();
    CharString* cc = new CharString("test@#$%^*()_+1234567890");
    q->push(cc);
    CharString* qq = (CharString*)q->pop();
    if(qq == cc) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << "(" << qq << ")" << endl;
    }
}

void testPriorityQueue() {
    cout << "PriorityQueue => ";
    PriorityQueue* q = new PriorityQueue();
    CharString* cc = new CharString("test@#$%^*()_+1234567890",24);
    q->insert(0,cc);
    CharString* qq = (CharString*)q->removeMin();
    if(qq == cc) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << "(" << qq << ")" << endl;
    }
}

void testHashMap() {
    cout << "HashMap => ";
    HashMap<CharString> hm = HashMap<CharString>(40000);
    CharString t1 = CharString("test1");
    CharString t1v = CharString("asdlkfjhlaksgh;\"'x';\30\1");
    CharString t2 = CharString("test2");
    CharString t2v = CharString("data2");
    hm.add(t1,t1v);
    hm.add(t2,t2v);

    CharString str1 = hm.get(t1);
    bool test1 = str1.Compare(t1v);
    CharString str2 = hm.get(t2);
    bool test2 = str2.Compare(t2v);
    if(test1 && test2) {
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << endl;
    }
}

void testDataStructures() {
    testFileCache();
    testBitMap();
    testQueue();
    testPriorityQueue();
    testHashMap();

    ConcurrentLinkedList<int> cll;
    ConcurrentLinkedList<CharString> cll2;
    ConcurrentLinkedList<CharString*> cll3;
    ConcurrentLinkedList<CharString**> cll4;
    CharString** p = (CharString**)malloc(sizeof(CharString));
    p[0] = new CharString("blah");
    cll.add(1);
    cll2.add(CharString("blah"));
    cll3.add(new CharString("blah"));
    cll4.add(p);

    cout << "Datastructures test Done" << endl;
}
