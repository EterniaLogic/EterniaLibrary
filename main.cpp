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

#include <iostream>

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

int main(){
#ifdef DEBUG
	//testGravity(); // tests Gravity calculation
	//testMath();
	//testParsers();
	//testDataStructures();
	
	
#endif
}
