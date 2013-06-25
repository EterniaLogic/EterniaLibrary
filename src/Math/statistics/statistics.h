//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Statistics_h
#define Statistics_h

// Create statistical system
// manages numbers and data.

// Internal fields:
//  Sampling
//  Classification
//  Probability
//  Regression (Functions from points)
//  Series
//  Data Analysis


#include "../struct/vector.h"
#include "../../Data/DoubleList.h"

enum SAMPLERTYPE {SAMPLERDouble, SAMPLERVector, SAMPLERVectorWWeight};

class Statistics
{
    SAMPLERTYPE type;
    DoubleList dList();
    
public:
    Statistics();
    
    // Data collection (Please use only one type at a time for each sampler)
    void sampleDouble(double number); // adds a double
    void sampleVector(vector* v); // add a vector
    void sampleVectorWithWeight(vector* v, double weight); // adds a vector with a weight (trails)
    
    
    // Data Analysis
    
    // double data
    double getMean(); // used to get the average of a list of Doubles
    vector* getMedian(); // get the number is in the "Middle"
    vector* getMode(); // returns the number that occurs the most times
    double getRange(); // determines that maximum possible data value
    double getVariance(); // determines the variance of the values sum[(i-mean)^2]
    double getDeviation(); // determines the standard deviation of the points sqrt(variance)
    double getQuartile(int quartile); // returns the quarter*quartile (ie: 1/4*2 = second quarter of the data)
    double getIQR(); // returns the Inter-Quartile range
    
    //vector data
    vector* getMeanVector(); // returns the average vector, sample with the weight to act as a center of mass
    vector* getMedianVector(); // returns vector that is in the "Middle" of all of the vectors
    vector* getModeVector(); // returns the vector with most occurences
    double getRangeVector(); // determines the largest vector (from origin)
};

#endif
