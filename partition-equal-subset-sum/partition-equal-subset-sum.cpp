class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++)
        {
            total += nums[i];
        }
        if(total % 2 == 1)
        {
            return false;
        }
        int sum = total/2;
        int dp[nums.size()][sum+1];
        memset(dp, false, sizeof(dp));
        for(int i=0;i<=sum;i++)
        {
            dp[0][i] = false;
        }
        for(int j=0;j<nums.size();j++)
        {
            dp[j][0] = true;
        }
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j - nums[i] >= 0)
                {
                    dp[i][j] = dp[i-1][j] | dp[i-1][j - nums[i]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][sum];
    }
};
