#define MOD 10^9+7
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        long long int dp[arr.size()];
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]] = i;
            dp[i] = 1;
        }
        long long int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    int right = arr[i]/arr[j];
                    if(mp.find(right) != mp.end())
                    {
                        dp[i] += (dp[j] * dp[mp[right]])%1000000007;
                    }
                }
            }
            
        }
        for(int i=0;i<arr.size();i++)
        {
            ans = (ans+dp[i])%1000000007;
        }
        return ans;
    }
};