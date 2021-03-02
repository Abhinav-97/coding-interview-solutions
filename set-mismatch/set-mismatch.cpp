class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int xor1 = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            xor1 ^= nums[i];
        }
        for(int i=1;i<=nums.size();i++)
        {
            xor1 ^=i;
        }
        int least_set_bit = xor1 & ~(xor1-1);
        int part0 = 0;
        int part1 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] & least_set_bit)
            {
                part0 ^=nums[i];
            }
            else{
                part1 ^=nums[i];
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(i & least_set_bit)
            {
                part0 ^= i;
            }
            else{
                part1 ^= i;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == part0)
            {
                ans[0] = part0;
                ans[1] = part1;
            }
            else if(nums[i] == part1)
            {
                ans[0] = part1;
                ans[1] = part0;
            }
        }
        return ans;
    }
};