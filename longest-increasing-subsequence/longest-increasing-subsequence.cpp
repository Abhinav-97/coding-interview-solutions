class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int dp[nums.size()];
        dp[0] = 1;
        int ans = 1;
        for(int i=1;i<nums.size();i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};