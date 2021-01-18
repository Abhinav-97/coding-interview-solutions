class Solution {
public:
    string vowelString = "aeiou";
    int countVowelStrings(int n) {
        int ans = 0;
        helper(n, 0, ans);
        return ans;
    }
    void helper(int n, int vowelIndex, int &ans)
    {
        if(n == 0)
        {
            ans++;
            return;
        }
        if(vowelIndex > vowelString.size())
        {
            return;
        }
        for(int i=vowelIndex;i<vowelString.size();i++)
        {
            helper(n-1, i, ans);
        }
    }
};
