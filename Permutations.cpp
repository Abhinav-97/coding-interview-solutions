/*Permuatations backtracking https://leetcode.com/problems/permutations/*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        if(nums.empty())
        {
            return ans;
        }
        vector<int> permutation;
        permuteRecursion(ans, nums, permutation);
        return ans;
    }
    
    void permuteRecursion(vector< vector<int> > &ans, vector<int> &nums, vector<int> &permutation)
    {
        if(nums.empty())
        {
            ans.push_back(permutation);
        }
        for(int i=0;i<nums.size();i++)
        {
            permutation.push_back(nums[i]);
            vector<int> newNums = nums;
            newNums.erase(newNums.begin()+i);
            permuteRecursion(ans, newNums, permutation);
            permutation.pop_back();
        }
    }
};