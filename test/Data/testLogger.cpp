#include "testLogger.h"


void testLogger(){
    Logger A, B, C, D;
    A = Logger("A.log", "[A]",false,true,true);
    B = Logger("B.log", "[B]",true,false,true);
    C = Logger("C.log", "[C]",true,true,false);
    D = Logger("D.log", "[D]",true,true,true);
    
    // wait
    sleep(1);
    A.log("AA");
    B.log("BB");
    C.log("CC");
    D.log("DD");
    sleep(1);
}
