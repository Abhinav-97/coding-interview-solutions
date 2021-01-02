class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        for(int val=1;val<=amount;val++)
        {
            int minWays = INT_MAX;
            for(int i=0;i<coins.size();i++)
            {
                if(val >= coins[i] && dp[val-coins[i]] != -1)
                {
                    minWays = min(minWays, dp[val - coins[i]] + 1);
                }
            }
            if(minWays == INT_MAX)
            {
                dp[val] = -1;
            }
            else{
                dp[val] = minWays;
            }
        }
        return dp[amount];
    }
};
