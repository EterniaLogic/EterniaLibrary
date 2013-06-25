//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "src/test.h"
// include most sections to find include errors if any
#include "src/Economics/economics.h"
#include "src/Social/Government/Government.h"
#include "src/Math/statistics/statistics.h"

int main(){
#ifdef DEBUG
	//testGravity(); // tests Gravity calculation
	//testMath();
	//testParsers();
	testDataStructures();
#endif
}
