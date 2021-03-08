class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, bool> mp;   
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]] = true;
        }
        for(int i=0;i<words.size();i++)
        {
            if(mp[words[i]] == false)
            {
                continue;
            }
            for(int j=1;j<words[i].length();j++)
            {
                string substring = words[i].substr(j, words[i].length()-j);
                if(mp.find(substring) != mp.end())
                {
                    mp[substring] = false; 
                }
            }
        }
        int ans = 0; 
        for(auto it = mp.begin();it!=mp.end();++it)
        {
            if(it->second == true)
            {
                ans += it->first.length()+1;
            }
            
        }
        return ans;
    }
};