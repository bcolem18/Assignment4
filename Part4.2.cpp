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
     int val=57;
     int n = 19;
     int pos = -1;
     int res = n;
     
     for(int i=0; i<n; i=(i*2)+1)
     {
             int begin=i; 
             int end=(i*2)+1; 
            res = n; 
            #pragma omp parallel for reduction(min:res)
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
    return 0;
}