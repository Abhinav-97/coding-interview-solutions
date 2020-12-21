class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProducts(nums.size()), rightProducts(nums.size());
        int leftProduct = 1;
        int rightProduct = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0)
            {
                leftProduct *= nums[i-1];
                leftProducts[i] = leftProduct;
            }
            else{
                leftProducts[i] = leftProduct;
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i < nums.size()-1)
            {
                rightProduct *= nums[i+1];
                rightProducts[i] = rightProduct;
            }
            else{
                rightProducts[i] = rightProduct;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            cout<<rightProducts[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<nums.size();i++)
        {
            cout<<leftProducts[i]<<" ";
        }
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            ans.push_back(leftProducts[i]*rightProducts[i]);
        }
        return ans;
        
        
    }
};
