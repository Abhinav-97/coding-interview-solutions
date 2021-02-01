class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        int ans = coinChangeDP(coins, amount, dp);
        return ans;
    }
    int coinChangeDP(vector<int>& coins, int amount, vector<int> &dp)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(amount < 0)
        {
            return INT_MAX;
        }
        if(dp[amount] != 0)
        {
            return dp[amount];
        }
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int ways = coinChangeDP(coins, amount-coins[i], dp);
            if(ways != INT_MAX && ways != -1 && ways+1 < ans)
            {
                ans = ways+1;
            }
        }
        // cout<<ans<<" ";
        if(ans == INT_MAX)
        {
            return dp[amount] = -1;
        }
        return dp[amount] = ans;
    }
};