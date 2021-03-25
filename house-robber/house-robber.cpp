class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = helper(nums, 0, dp);
        return ans;
    }
    
    int helper(vector<int> &nums, int i, vector<int> &dp)
    {
        if(i >= nums.size())
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int robHouse = nums[i] + helper(nums, i+2, dp);
        int dontRobHouse = helper(nums, i+1, dp);
        return dp[i] = max(robHouse, dontRobHouse);
    }
};