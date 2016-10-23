#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;




int main()
{
    
    int arr[19]= {1,1,1,1,5,5,5,5,5,7,7,7,7,8,9,10,11,12,55};
    //int size= arr.length; 
    
    int val=7; 
    //int min=0; 
    int pos=20; 
    int result=0; 
    
    
    #pragma omp parallel 
    {
        
       #pragma omp for reduction(min:pos)
        
            for(int i=0; i<19; i++)
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
    
    
    
    
    
    
    