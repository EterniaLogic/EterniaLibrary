#include "testPType.h"

void testPType(){
    PType<int> a,b;
    a=20;
    b=31;
    
    a += b;
    a+=100;
    
    PType<float> c,d;
    c=10;
    d=90;
    
    c+=60;
    
    PType<double> e,f;
    e=10;
    f=90;
    
    e+=1.;
    
    e.testViolate();
    cout << e.isViolated() << endl;
    e+=1;
    
    _DBG("SIZEi: " << sizeof(a));
    _DBG("SIZEf: " << sizeof(c));
    _DBG("SIZEd: " << sizeof(e));
}
