class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length_power_set = 1 << nums.size();
        // cout<< length_power_set;
        vector<vector<int>> ans;
        for(int i=0;i<length_power_set;i++)
        {
            // cout<<i;
            vector<int> res;
            for(int j=0;j<nums.size();j++)
            {
                if(i & (1 << j))
                {
                    res.push_back(nums[j]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};