class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        while(left < s.length() && right < s.length())
        {
            if(mp.find(s[right]) == mp.end())
            {
                mp[s[right]]++;
                right++;
                
            }
            else{
                mp[s[left]]--;
                if(mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};