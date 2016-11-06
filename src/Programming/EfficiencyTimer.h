//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef EFFICIENCYTIMER_H_
#define EFFICIENCYTIMER_H_

class EfficiencyTimer {
        double BaseTime;
    public:
        EfficiencyTimer();
        void Start();
        void StopAndReport(double DataDone);
};

#endif /*EFFICIENCYTIMER_H_*/
