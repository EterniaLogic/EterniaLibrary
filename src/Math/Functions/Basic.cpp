//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------


#include "Basic.h"

#define ACCURACY 10

namespace Math
{
    // flips value if negative to positive
    double abs(double a){
        if(a < 0) a=a*-1;
        return a;
    }
    
    // power of function, gets the exponent a^b
    double pow(double x, double b){
        double out = 1;
        
        for(int i=0;i<abs(b);i++){
            out *= x;
        }
        
        // reverse if b is negative.
        if(b < 0) out = 1/out;
        return out;
    } 
    
    // return x^e
    // Used from:
    //  http://www.codeproject.com/Tips/311714/Natural-Logarithms-and-Exponent
    double powe(double Exponent)
	{
		double X, P, Frac, I, L;
		X = Exponent;
		Frac = X;
		P = (1.0 + X);
		I = 1.0;
				
		do
		{
			I++;
			Frac *= (X / I);
			L = P;
			P += Frac;
		}while(L != P);
			
		return P;
	}
    
    
    
    // natural log function
    // Used from:
    //  http://www.codeproject.com/Tips/311714/Natural-Logarithms-and-Exponent
    double ln(double x){
        double A,L,R,P;
        double N = 0.00;
        while(P >= E)  
		{
			P /= E;
			N++;
		}
		N += (P / E);
		P = x;
		
		do
		{
			A = N;
			L = (P / (powe(N - 1.0)));
			R = ((N - 1.0) * E);
			N = ((L + R) / E);
		}while(N != A);
		
		return N;
    }
    
    // direct base log
    double log(double base, double x){
        return ln(x) / ln(base);
    } 
    
    // finds the factorial of the number
    double factorial(double x){
        if(x <= 0) return 1; 
        
        return x * factorial(x-1);
    }
    
    // ref: http://www.cs.uni.edu/~jacobson/C++/newton.html
    double sqrt(double number)
    {
        const double ACC=0.001;
        double lower, upper, guess;

         if (number < 1)
         {
          lower = number;
          upper = 1;
         }
         else
         {
          lower = 1;
          upper = number;
         }

         while ((upper-lower) > ACC)
         {
          guess = (lower + upper)/2;
          if(guess*guess > number)
            upper =guess;
          else
            lower = guess; 
         }
         return (lower + upper)/2;
    } 
}
