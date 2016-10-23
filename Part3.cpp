#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;



double func_1(double x, int intensity)
{
	
	for(int i=0; i<intensity; i++)
	{
		x=x*x; 
	}
	return 1;
}



double integral (double a, double b, int N, int intensity)
{

	double sum=0;

	 for(int i=0; i<N; i++)//
			{
				const double h= (b-a)/N;
				sum+= func_1(a + (i+.5) *h ,intensity)  * h;

			}
		return sum;
	}







int main(int argc, char*argv[])
{
    if(argc==4)
    {
        
    double a; 
	double b; 
	int N; 
	int intensity; 
	
	a= atof(argv[1]); 
	b=atof(argv[2]); 
	N=atoi(argv[3]); 
	intensity=atoi(argv[4]);
	
	
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
}