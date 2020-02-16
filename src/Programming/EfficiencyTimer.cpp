

#include "EfficiencyTimer.h"
#include <iostream>
#include <ctime>

using namespace std;

EfficiencyTimer::EfficiencyTimer() {
	BaseTime = 0;
}

void EfficiencyTimer::Start() {
    BaseTime = clock()/CLOCKS_PER_SEC;
}

// report % efficiency of algorithm.
void EfficiencyTimer::StopAndReport(double workDone) {
    // calculate efficiency over time.
    double totalTime = ((double)clock()/CLOCKS_PER_SEC) -BaseTime;
    cout << (100-(workDone/(totalTime*(double)CLOCKS_PER_SEC))*100) << "%";
}
