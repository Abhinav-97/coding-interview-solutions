// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<pair<long long, int>> st;
        st.push(make_pair(arr[0], 0));
        vector<long long> ans(arr.size());
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && st.top().first < arr[i])
            {
                ans[st.top().second] = arr[i];
                st.pop();
            }
            st.push(make_pair(arr[i], i));
        }
        while(!st.empty())
        {
            ans[st.top().second] = -1;
            st.pop();
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends