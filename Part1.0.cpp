#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) //Size of array, number of thread, scheduling policy

{
 
 
 
 if(argc==3)
 {
     
 int N= atof(argv[1]);
 int threadNum= atof(argv[2]); 
 
 srand(time(NULL)); 
 
 
 int *arr= new int[N]; 
 
  for(int i=0; i<N; i++)
 {
     
     arr[i]= (rand()%30)+1; 
    std::cout <<arr[i] << std::endl;
    
     

     
     
     
     
 } //generate array
 



 
omp_set_num_threads(threadNum); 
 omp_set_schedule(omp_sched_dynamic, 64);
 

clock_t begin=clock();

#pragma omp parallel 
{
 //threads execute
 
 
 
 #pragma omp for schedule(runtime)
 
 
 for(int i=0; i<N; i++)
 {
     
    arr[i]= arr[i]*arr[i];
    std::cout<<"      "<<std::endl; 
    std::cout <<arr[i]<< std::endl;
    
      } 
      
      
      
 
    
}
clock_t end=clock();

std::cout << "Time elapsed: " << end-begin << " ms"<<std:: endl;

    
}

}