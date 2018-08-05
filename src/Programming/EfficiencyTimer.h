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
