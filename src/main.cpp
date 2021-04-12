//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include <time.h>

#include "../test/test.h"
#include "include.h"
#include "asm/asm1.h"


#include "Engineering/Chemistry/Composite.h"

#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN64
   #define WINDOWSXX
   #define FULLVERSION_STRING "1.123.3"
#elif _WIN32
   #define WINDOWSXX
   #define FULLVERSION_STRING "1.123.3"
#else
   #define LINUXX
   #include <execinfo.h>
   void handler(int sig) {
        void *array[10];
        size_t size;

        // get void*'s for all entries on the stack
        size = backtrace(array, 10);

        // print out all the frames to stderr
        fprintf(stderr, "\n\nError: signal %d:   (11 = SEGV)\n", sig);
        backtrace_symbols_fd(array, size, STDERR_FILENO);
        exit(1);
   }
#endif

#include "version.h"

#define DEBUG
// input redirection
void InputRedirection::handleInputLine(CharString* input) {
    double ii = 0;
    double time1 = clock()/CLOCKS_PER_SEC;
    double basetime = clock()/CLOCKS_PER_SEC;
    //cout << "'" << input << "'" << endl; // 'test'
    
    if(input->Compare("exit",4)) {
        this->stop = true;
    } else if(input->Compare("help",4)) {
        cout << "[Commands]:" << endl;
        cout << "  test         - lists possible tests" << endl;
        cout << "  exit         - Exits the program" << endl;
    } else if(input->Compare("MathTest",8)) {
        testMath();
    } else if(input->Compare("AsmTest",7)) {
        testASM();
    } else if(input->Compare("ExHashTest",10)) {
        testExHash();
    } else if(input->Compare("PhysTest",8)) {
        //testGravity();
        testViscosityCurve();
    } else if(input->Compare("EngineerTest",12)) {

    } else if(input->Compare("AbstractDB",10)) {
        testAbstractDB();
    } else if(input->Compare("EventHandler",12)) {
        testEventHandler();
    } else if(input->Compare("CTest",5)) {
        CharString* c = new CharString("-12038.22828282302012031929319",30);
        cout << "STRTEST Float: -" << c << " = " << c->getFloat() << endl;
        c = new CharString("0.0000000000000000000000000123",30);
        cout << "STRTEST Float: " << c << " = " << c->getFloat() << endl;
        c = new CharString("-120382282828230201203.1929319",30);
        cout << "STRTEST Float: -" << c << " = " << c->getFloat() << endl;
        c = new CharString("-1.2345e+9",10);
        cout << "STRTEST Float: -" << c << " = " << c->getFloat() << endl;
        c = new CharString("1.2345e+120",11);
        cout << "STRTEST Float: -" << c << " = " << c->getFloat() << endl;
    } else if(input->Compare("LinearTest",10)) {
        char* a = new char();
        strcpy(a,"[LinearTest] ");
        testStructures(a);
    } else if(input->Compare("DataStruTest",12)) {
        testDataStructures();
    } else if(input->Compare("PTypeTest",9)) {
        testPType();
    } else if(input->Compare("SerializerTest",12)) {
        testSerializers();
    }else if(input->Compare("NetworkTest",11)) {
        testNetwork();
    } else if(input->Compare("TestALL",8)) {
        testDataStructures();
        testMath();
        char a[14];
        strcpy(a,"[LinearTest] ");
        testStructures(a);
        testGravity();
        //testASM();
    } else if(input->Compare("test",4)) {
        cout << "[Tests]:" << endl;
        cout << "  AbstractDB    - tests the Abstract Database" << endl;
        cout << "  AsmTest       - tests embedded assembler" << endl;
        cout << "  ExHashTest    - tests embedded assembler" << endl;
        cout << "  MathTest      - tests basic math systems" << endl;
        cout << "  LinearTest    - tests linear algebra" << endl;
        cout << "  EventHandler  - tests Event Handler" << endl;
        cout << "  EngineerTest  - tests Engineering systems" << endl;
        cout << "  PhysTest      - tests Physics systems" << endl;
        cout << "  DataStruTest  - tests Data structures" << endl;
        cout << "  NetworkTest   - tests Networking systems (P2p, Server, Client, ect)" << endl;
        ///cout << "  RenderTest    - tests rendering systems" << endl;
        cout << "  SerializerTest- tests rendering systems" << endl;
        cout << "  TestALL       - tests all the above" << endl;
    } else {
        cout << "Unknown command; Try `help`." << endl;
    }
    double totalTime = ((double)clock()/CLOCKS_PER_SEC) - basetime;
    cout << "Total test time: " << totalTime*1000 << " Milliseconds" << endl;
}

// ref: http://www.programmersheaven.com/mb/beginnercpp/242683/244327/re-which-file-should-i-include-using-sleep/
void sleep( time_t delay ) {
    time_t timer0, timer1;
    time( &timer0 );
    do {
        time( &timer1 );
    } while (( timer1 - timer0 ) < delay );
}



int main() {
    cout << "Version: " << FULLVERSION_STRING << endl;
    
#ifdef LINUXX
    //1signal(SIGSEGV, handler);   // install a handler
#endif

#ifdef DEBUG
    //CharString c = "test";
    //cout << c << endl;

    
    //testGravity(); // tests Gravity calculation
    //testViscosityCurve();
    //testLogger();
    //testMath();
    //testParsers();
    //testDataStructures();
    //testASM();


    /*cout << "float: " << sizeof(float) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "short: " << sizeof(short) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "double: " << sizeof(double) << endl;*/

    /*CharString c = CharString("abcde|+xabcde|+abcde|+abcde\0",27);
    LinkedList<CharString> a = c.split(CharString("|+",2));
    cout << "a: " << a.size() << endl;
    
    for(int i=0;i<a.size();i++){
        CharString c = *a.get(i);
        cout << '\t' << c.get() << endl;
    }*/

    //testPType();
    //malloc_stats();
    //malloc_stats();
    
    //testFileCache();
    
    //testExHash();
    //testHTTP();
    //testNetwork();
    //testOrbit();
    
    //CompositeGas::printCompositeGasses();
    
    //testMSGServer();
    
    //testLSTM_XOR4();
    //testSerializers();
    //testAPICore();
    //testARB();
    //malloc_stats();
    
#endif

    InputRedirection* ir = new InputRedirection();
    ir->redirect();
    return 0;
}
