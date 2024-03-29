// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int ans = helper(W, wt, val, n, 0);
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i == 0 || j == 0)
               {
                   dp[i][j] = 0;
               }
               else{
                   if(j >= wt[i-1])
                   {
                       dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                   }
                   else{
                       dp[i][j] = dp[i-1][j];
                   }
               }
           }
       }
       
       return dp[n][W];
        
    }
    
    int helper(int W, int wt[], int val[], int n, int idx)
    {
        if(idx >= n)
        {
            return 0;
        }   
        if(W < wt[idx])
        {
            return helper(W, wt, val, n, idx+1);
        }
        return max(helper(W-wt[idx], wt, val, n, idx+1)+val[idx],
                    helper(W, wt, val, n, idx+1));
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends