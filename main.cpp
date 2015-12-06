//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include <time.h>

#include "src/test.h"
// include most sections to find include errors if any
#include "src/Economics/economics.h"
#include "src/Social/Government/Government.h"
#include "src/Math/statistics/statistics.h"
//#include "src/Engineering/Electrical/Interfaces/FPGA/Basys2.h"
#include "src/Parsing/InputRedirection.h"
#include "src/asm/asm1.h"

#include <iostream>

#define DEBUG


// input redirection
void InputRedirection::handleInputLine(CharString* input)
{
    double ii = 0;
    double time1 = clock()/CLOCKS_PER_SEC;
    double basetime = clock()/CLOCKS_PER_SEC;
    if(input->Compare("exit",4))
    {
        this->stop = true;
    }
    else if(input->Compare("help",4))
    {
        cout << "[Commands]:" << endl;
        cout << "  test         - lists possible tests" << endl;
        cout << "  exit         - Exits the program" << endl;
    }
    else if(input->Compare("MathTest",8))
    {
        testMath();
    }
    else if(input->Compare("AsmTest",7))
    {
        testASM();
    }
    else if(input->Compare("PhysTest",8))
    {
        testGravity();
    }
    else if(input->Compare("EngineerTest",12))
    {

    }if(input->Compare("AbstractDB",10)){
        testAbstractDB();
    }else if(input->Compare("EventHandler",12)){
        testEventHandler();
    }
    else if(input->Compare("GameTest",8))
    {
    }
    else if(input->Compare("LinearTest",10))
    {
        char* a = new char();
        strcpy(a,"[LinearTest] ");
        testStructures(a);
    }
    else if(input->Compare("DataStruTest",12))
    {
        testDataStructures();
    }else if(input->Compare("SerializerTest",12)){
        testSerializers();
    }else if(input->Compare("TestALL",8))
    {
        testDataStructures();
        testMath();
        char a[14];
        strcpy(a,"[LinearTest] ");
        testStructures(a);
        testGravity();
        testASM();
    }
    else if(input->Compare("test",4))
    {
        cout << "[Tests]:" << endl;
        cout << "  AbstractDB   - tests the Abstract Database" << endl;
        cout << "  AsmTest       - tests embedded assembler" << endl;
        cout << "  MathTest      - tests basic math systems" << endl;
        cout << "  LinearTest    - tests linear algebra" << endl;
        cout << "  GameTest      - tests backend game systems" << endl;
        cout << "  EventHandler  - tests Event Handler" << endl;
        cout << "  EngineerTest  - tests Engineering systems" << endl;
        cout << "  PhysTest      - tests Physics systems" << endl;
        cout << "  DataStruTest  - tests Data structures" << endl;
        cout << "  NetworkTest   - tests Networking systems (P2p, Server, Client, ect)" << endl;
        cout << "  RenderTest    - tests rendering systems" << endl;
        cout << "  SerializerTest- tests rendering systems" << endl;
        cout << "  TestALL       - tests all the above" << endl;
    }
    else
    {
        cout << "Unknown command; Try `help`." << endl;
    }
    double totalTime = ((double)clock()/CLOCKS_PER_SEC) - basetime;
    cout << "Total test time: " << totalTime*1000 << " Milliseconds" << endl;
}

// ref: http://www.programmersheaven.com/mb/beginnercpp/242683/244327/re-which-file-should-i-include-using-sleep/
void sleep( time_t delay )
{
    time_t timer0, timer1;
    time( &timer0 );
    do
    {
        time( &timer1 );
    }
    while (( timer1 - timer0 ) < delay );
}

int main()
{
#ifdef DEBUG
    //testGravity(); // tests Gravity calculation
    //testMath();
    //testParsers();
    //testDataStructures();
    testAbstractDB();

    //b2 = new Basys2();
    InputRedirection* ir = new InputRedirection();
    ir->redirect();
    //b2->~Basys2();*/

#endif
    return 0;
}
