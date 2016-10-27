#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
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
    
    
     

     
     
     
     
 } //generate array 
    
    #pragma omp parallel 
    {
        
       #pragma omp for reduction(min:pos)
        
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
        
        
        
        
        
    } 
        
        
    }
    
    
    
    
    
    
    