class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int> combination; 
        combinationSumRec(candidates, target, 0, ans, combination);
        return ans;
    }
    
    void combinationSumRec(vector<int> &candidates, int target, int index, vector< vector<int> > &ans, vector<int> combination)
    {
        if(target == 0)
        {
            ans.push_back(combination);
        }
        if(target < 0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            combination.push_back(candidates[i]);
            combinationSumRec(candidates, target-candidates[i], i, ans, combination);
            combination.pop_back();
        }
    }
};
