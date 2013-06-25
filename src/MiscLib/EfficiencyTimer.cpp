//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "EfficiencyTimer.h"
#include <iostream>

using namespace std;

EfficiencyTimer::EfficiencyTimer()
{
}

void EfficiencyTimer::Start(){
	BaseTime = clock()/CLOCKS_PER_SEC;
}

// report % efficiency of algorithm.
void EfficiencyTimer::StopAndReport(double workDone){
	// calculate efficiency over time.
	double totalTime = ((double)clock()/CLOCKS_PER_SEC) -BaseTime;
	cout << (100-(workDone/(totalTime*(double)CLOCKS_PER_SEC))*100) << "%";
}
