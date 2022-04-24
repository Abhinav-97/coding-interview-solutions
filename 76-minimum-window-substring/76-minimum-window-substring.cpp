class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> pattern_map;
        unordered_map<int, int> string_map;
        int ans_left = -1;
        int ans_right = -1;
        int min_length = INT_MAX;
        int string_cnt = 0;
        int left = 0;
        int right = 0;
        for(int i=0;i<t.length();i++)
        {
            pattern_map[t[i]]++;
        }
        while(left < s.length() and right < s.length())
        {
            // cout<<s[right]<<" ";
            string_map[s[right]]++;
            if(pattern_map.find(s[right]) != pattern_map.end() && string_map[s[right]] == pattern_map[s[right]])
            {
                string_cnt++;
            }
            right++;
            cout<<string_cnt;
            if(string_cnt == pattern_map.size())
            {
                while(string_cnt == pattern_map.size() && left < right)
                {
                    // cout<<min_length<<" "<<endl;
                    // cout<<right<<" "<<left<<endl;;
                    if(right - left < min_length)
                    {
                        ans_left = left;
                        ans_right = right;
                        min_length = right-left;
                    }
                    string_map[s[left]]--;
                    if(pattern_map.find(s[left]) != pattern_map.end() && string_map[s[left]] < pattern_map[s[left]])
                    {
                        string_cnt--;
                    }
                    left++;
                    
                }
            }
        }
        // cout<<left<<right;
        
        string ans = "";
        if(ans_left == -1)
        {
            return ans;
        }
        for(int k=ans_left;k<ans_right;k++)
        {
            ans += s[k];
        }
        return ans;
    }
};