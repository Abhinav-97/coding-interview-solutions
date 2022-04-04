class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxNow = 0;
        for(int i=0;i<nums.size();i++)
        {
           
            maxSum = max(maxSum, maxNow+nums[i]);
            maxNow += nums[i];
            
            if(maxNow < 0)
            {
                maxNow = 0;
            }
            
        }
        return maxSum;
    }
};