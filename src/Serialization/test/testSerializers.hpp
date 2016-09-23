#include "../BasicSerializer.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

class TestSerializerClass : public BasicSerializer{
        char cc4=1;
        const char *tt = "a";

/*private:
        char cc;
        char cc1;
        int cc2;      */

public:
        TestSerializerClass();
};

TestSerializerClass::TestSerializerClass(){
        initSerializer((void*)this, sizeof(this));
        //initSerializer((void*)this, sizeof(this));
}


void testSerializers(){
        TestSerializerClass *tsc1 = new TestSerializerClass(); // = new TestSerializerClass();

        //char* data = tsc1.serialize();

        int size=100;
        char* data = (char*)calloc(size+1,sizeof(char));
        data[size] = 0x0; // null so that info can be output to console

        // copy data over
        for(int i=0;i<size;i++){
                //data[i] = (char)(((char*)tsc1)[i]);
                cout << data[i];
        }

        cout << data << endl;
}
