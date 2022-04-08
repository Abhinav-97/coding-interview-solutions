class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rightProduct(nums.size()+1);
        vector<int> leftProduct(nums.size()+1);
        int rightP = 1;
        int leftP = 1;
        for(int i=0;i<nums.size();i++)
        {
            rightP *= nums[i];
            rightProduct[i] = rightP;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            leftP *= nums[i];
            leftProduct[i] = leftP;
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            // cout<<i;
            int rightPart = 1;
            int leftPart = 1;
            if(i > 0)
            {
                rightPart = rightProduct[i-1];
            }
            if(i < nums.size()-1)
            {
                leftPart = leftProduct[i+1];
            }
            ans[i] = rightPart*leftPart;
        }
        return ans;
        
    }
};