#ifndef RAND_H_
#define RAND_H_

#include <random>
#include <time.h>
#include <limits.h>
// This is not a random generator, just a set of functions to make random quick and easy to use via the C++11 Standard.

namespace Math{
    
    class Random{
    public:
        long seed;
        std::default_random_engine generator;
        Random(long seedx){
            seed=seedx;
            generator.seed(seedx);
        }
        
        Random(){
            seed=time(0x0); // standard random time seed
            generator.seed(time(0x0));
        }
        
        
        // drand(0, 1) => 0.75314, 0.5, 0.251232, ect.
        double nextDouble(double lower, double upper){
            std::uniform_real_distribution<double> unif(lower,upper);
            
            return unif(generator);
        }
        
        // between 0 and 1
        double nextDouble(){
            std::uniform_real_distribution<double> unif(0,1.0);
            
            return unif(generator);
        }
        
        double nextInt(int lower, int upper){
            std::uniform_int_distribution<int> unif(lower,upper);
            
            return unif(generator);
        }
        
        // lower assumed is 0
        unsigned int nextInt(unsigned int upper){
            std::uniform_int_distribution<int> unif(0,upper);
            
            return unif(generator);
        }
        
        // Wild integer, any number
        int nextInt(){
            std::uniform_int_distribution<int> unif(INT_MIN,INT_MAX);
            
            return unif(generator);
        }
        
        
        long nextLong(long lower, long upper){
            std::uniform_int_distribution<long> unif(lower,upper);
            
            return unif(generator);
        }
        
        // Wild Long
        long nextLong(){
            std::uniform_int_distribution<long> unif(LONG_MIN,LONG_MAX);
            
            return unif(generator);
        }
        
        // boolean
        bool nextBoolean(){
            return nextInt(0,1)==1 ? true : false;
        }
    };
}

#endif
