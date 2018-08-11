//Kadane's algo for maximum contigous subarray 

#include<bits/stdc++.h>
using namespace std;
maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN, max_here = 0;
    int max_element = INT_MIN;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] > max_element){
            max_element = A[i]; 
        }
        max_here += A[i];
        if(max_here < 0){
            max_here = 0;
        }
        if(max_so_far < max_here){
            max_so_far = max_here;
        }
    }
    if(max_so_far == 0){
        max_so_far = max_element;
    }
    return max_so_far;
}
