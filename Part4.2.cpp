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


int main(int argc, char *argv[])
{
    
    if(argc==4)
      
      {
      
      
    int n= atof(argv[1]);
    int threadNum= atof(argv[2]); 
    int val=atof(argv[3]);
    
    
     //int arr[19]= {1,1,1,1,5,5,5,5,5,7,7,7,7,8,9,10,11,12,55};
    // int val=57;
     //int n = 19;
     int pos = -1;
     int res = n;
     
     srand(time(NULL)); 
 
 
 int *arr= new int[n]; 
 
  for(int i=0; i<n; i++)
 {
     
     arr[i]= (rand()%100)+1; 
    
    
     

     
     
     
     
 } //generate array 
 
  
omp_set_num_threads(threadNum); 
omp_set_schedule(omp_sched_dynamic, 100000);

std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
     
     for(int i=0; i<n; i=(i*2)+1)
     {
             int begin=i; 
             int end=(i*2)+1; 
            res = n; 
            #pragma omp parallel for schedule(runtime) reduction(min:res)
            for(int j=begin;j<=end;j++)
            {
                if(arr[j] == val) {
                    res  = j;
                }
            }
            
            
            if(res != n) {
                pos = res;
                break;
            }
            
        }
         
         
         
         
     
    
    cout << pos << endl;
   
    end = std::chrono::system_clock::now();
 std::chrono::duration<double> elapsed_seconds = end-start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 

  std::cout << "finished acomputation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

     return 0;
      }
}