class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> mp;
        for(int i=0;i<S.length();i++)
        {
            mp[S[i]] = i;
        }
        int firstIndex = 0;
        int lastIndex = 0;
        vector<int> ans;
        for(int i=0;i<S.length();i++)
        {
            if(i > lastIndex)
            {
                ans.push_back(lastIndex-firstIndex+1);
                firstIndex = lastIndex + 1;
            }
            lastIndex = max(lastIndex, mp[S[i]]);
        }
        ans.push_back(lastIndex-firstIndex+1);
        return ans;
    }
};