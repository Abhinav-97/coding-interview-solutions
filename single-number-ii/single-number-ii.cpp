class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0; // variable for number which occurs one time
        int twos = 0; // variable for number which occurs two times
        
        for(int i=0;i<nums.size();i++)
        {
            ones = (nums[i]^ones)&(~twos);
            twos = (nums[i]^twos)&(~ones);
        }
        return ones;
    }
};