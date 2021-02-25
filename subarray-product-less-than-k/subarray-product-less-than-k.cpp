class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int prod = 1;
        while(left < nums.size() && right < nums.size())
        {
            
            if(right < nums.size() && prod*nums[right] < k)
            {
                ans += right-left+1;
                prod = prod*nums[right];
                right++;
            }
            else{
                prod = prod/nums[left];
                if(prod == 0)
                {
                    prod = 1;
                    left++;
                    right++;
                }
                else{
                    left++;
                    
                }
            }
        }
        return ans;
    }
};