class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size());
        vector<int> rightProduct(nums.size());
        
        leftProduct[0] = 1;
        rightProduct[nums.size()-1] = 1;
        for(int i=1;i<nums.size();i++)
        {
            leftProduct[i] = nums[i-1]*leftProduct[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            rightProduct[i] = nums[i+1]*rightProduct[i+1];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {   cout<<leftProduct[i]<<" "<<rightProduct[i]<<endl;
            ans.push_back(leftProduct[i]*rightProduct[i]);
        }
        return ans;
    }
};