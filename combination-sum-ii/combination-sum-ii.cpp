class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        combinationSumRec(candidates, target, 0, combination, ans);
        
        return ans;
    }
    
    void combinationSumRec(vector<int> &candidates, int target, int index, vector<int> combination, vector< vector<int> > &ans)
    {
        if(target == 0)
        {
            ans.push_back(combination);
        }
        if(target < 0)
        {
            return;
        }
        if(index == candidates.size())
        {
            return;
        }
        for(int i = index;i<candidates.size();i++)
        {
            if(i == index || candidates[i] != candidates[i-1])
            {
                combination.push_back(candidates[i]);
                combinationSumRec(candidates, target-candidates[i], i+1, combination, ans);
                combination.pop_back();
            }
        }
    }
};
