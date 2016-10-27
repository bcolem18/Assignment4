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




int main(int argc, char *argv[]) //size of array and num of thread
{
    
    if(argc==4) 
    
    {
    
    int N= atof(argv[1]);
    int threadNum= atof(argv[2]); 
    
    
   // int arr[19]= {1,1,1,1,5,5,5,5,5,7,7,7,7,8,9,10,11,12,55};
    //int size= arr.length; 
    
     

    
    int val=atof(argv[3]); 
    //int min=0; 
    int pos=N+1; 
    int result=0; 
    
    
    srand(time(NULL)); 
 
 
 int *arr= new int[N]; 
 
  for(int i=0; i<N; i++)
 {
     
     arr[i]= (rand()%100)+1; 
    
    
     std::cout<<arr[i]<<std::endl; 

     
     
     
     
 } //generate array 
 
  
omp_set_num_threads(threadNum); 
omp_set_schedule(omp_sched_dynamic, 100000);

std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
 
    
    #pragma omp parallel 
    {
        
       #pragma omp for schedule(runtime) reduction(min:pos)
        
            for(int i=0; i<N; i++)
                {
                   // result+=arr[i]; 
                  
                       if(arr[i]==val) 
                        {
                            if(i<pos)
                            {
                                pos=i; 
                            }
                           ;  //reduction(min:pos) 
                           
                        }  
                    
                }
      
          
      }
         std::cout<<pos<<std::endl;
        end = std::chrono::system_clock::now();
 std::chrono::duration<double> elapsed_seconds = end-start;
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 

  std::cout << "finished acomputation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

        
        
        
        
    } 
        
        
    }
    
    
    
    
    
    
    