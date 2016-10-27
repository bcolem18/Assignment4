#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
#include<chrono>
#include<ctime>
#include<time.h>
using namespace std;



double func_1(double x, int intensity)
{
	
	for(int i=0; i<intensity; i++)
	{
		x=x*x; 
	}
	return 1;
}











int main(int argc, char*argv[])//set number of threads, a, b, intensity, 
{
    if(argc==6)
    {
        
    double a; 
	double b; 
	int N; 
	int intensity; 
	
	
	a= atof(argv[1]); 
	b=atof(argv[2]); 
	N=atoi(argv[3]); 
	intensity=atoi(argv[4]);
	 int threadNum= atof(argv[5]);
	 double sum=0; 
	 
	 
	 omp_set_num_threads(threadNum); 
omp_set_schedule(omp_sched_dynamic, 100000);
	
	std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
	
	
	#pragma omp parallel
	{
		
		
		#pragma omp for schedule(runtime)
		
		for(int i=0; i<N; i++)//
			{
				const double h= (b-a)/N;
				sum+= func_1(a + (i+.5) *h ,intensity)  * h;

			}
		
			
		
	}
        
        
 	cout << sum<< endl;       
        end = std::chrono::system_clock::now();
 std::chrono::duration<double> elapsed_seconds = end-start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 

  std::cout << "finished acomputation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";   
        
        
        
    }
    
    
    
    
    
    
    
    
}