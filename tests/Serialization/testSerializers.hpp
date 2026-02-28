#include "../../src/Serialization/SpecificSerializer.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

class TestSubClass : public SpecificSerializer{
public:
    CharString subname;
    LinkedList<int> testList;
    
    TestSubClass(){
        addSerial_N(subname, SSE_CharString);
        addSerial_N(testList, SSE_LinkedList);
        
        subname = "this list is cool!";
        testList.add(-23456789);
        testList.add(98765432);
    }
};


class TestClass : public SpecificSerializer{
public:
    int a;
    double hp;
    CharString name;
    TestSubClass subclass;

    TestClass(){
        addSerial_N(a, SSE_Int);
        addSerial_N(hp, SSE_double);
        addSerial_N(name, SSE_CharString);
        addSerial_N(subclass, SSE_SSerializer);
    }
};



void testSerializers() {
    TestClass c;
    c.a = 12345;
    c.hp = 100.12345;
    c.name = "test!";
    
    // output JSON
    cout << "JSON:\n" << endl;
    cout << c.toJSON() << endl;
    cout << "-----\n" << endl;
    cout.flush();
}
