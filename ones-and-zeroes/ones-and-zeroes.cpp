class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(strs, 0, m, n);
        return ans;
    }
    
    int helper(vector<string> &strs, int idx, int m, int n)
    {
        if(idx == strs.size())
        {
            return 0;
        }
        if(dp[idx][m][n] != -1)
        {
            return dp[idx][m][n];
        }
        int numZeros = 0;
        int numOnes = 0;
        for(int i=0;i<strs[idx].size();i++)
        {
            if(strs[idx][i] == '0')
            {
                numZeros++;
            }
            else if(strs[idx][i] == '1')
            {
                numOnes++;
            }
        }
        int taken = INT_MIN;
        if(numZeros <= m && numOnes <= n)
        {
            taken = helper(strs, idx+1, m-numZeros, n-numOnes) + 1;
        }
        int notTaken = helper(strs, idx+1, m, n);
        return dp[idx][m][n] = max(taken, notTaken);
    }
};