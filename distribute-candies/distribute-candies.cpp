class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, bool> mp;
        for(int i=0;i<candyType.size();i++)
        {
            mp[candyType[i]] = true;
        }
        return min(mp.size(), candyType.size()/2);
    }
};