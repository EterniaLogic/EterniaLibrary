#include "../SpecificSerializer.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


class TestClass : public SpecificSerializer{
public:
    int a;
    double hp;
    CharString name;

    TestClass(){
        addSerial_N(a, SSE_Int);
        addSerial_N(hp, SSE_double);
        addSerial_N(name, SSE_CharString);
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
