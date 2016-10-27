#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
#include <time.h>
#include <chrono>
#include<ctime>
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
    
    
     

     
     
     
     
 } //generate array
 



 
omp_set_num_threads(threadNum); 
omp_set_schedule(omp_sched_dynamic, 1000);
 

std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();

#pragma omp parallel 
{
 //threads execute
 
 
 
 #pragma omp for schedule(runtime)
 
 
 for(int i=0; i<N; i++)
 {
     
    arr[i]= arr[i]*arr[i];
 
    
      } 
      
   
      
 
    
}
 end = std::chrono::system_clock::now();
 std::chrono::duration<double> elapsed_seconds = end-start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 

  std::cout << "finished acomputation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    
}

}