// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    pair<int, int> a[nums.size()];
	    for(int i=0;i<n;i++)
	    {
	        a[i].first = nums[i];
	        a[i].second = i;
	    }
	    int ans = 0;
	    sort(a, a+n);
	    bool visited[n] = {0};
	    for(int i=0;i<n;i++)
	    {
	        if(visited[i] || a[i].second == i)
	        {
	            continue;
	        }
	        int cycle = 0;
	        int curr = i;
	        while(!visited[curr])
	        {
	            visited[curr] = true;
	            int next_pos = a[curr].second;
	            curr = next_pos;
	            cycle++;
	        }
	        ans += (cycle-1);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends