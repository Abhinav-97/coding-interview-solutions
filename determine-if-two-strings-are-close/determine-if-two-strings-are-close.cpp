class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
        {
            return false;
        }
        int charWord1[26] = {0};
        int charWord2[26] = {0};
        for(int i=0;i<word1.length();i++)
        {
            charWord1[word1[i] - 'a']++;
        }
        for(int i=0;i<word2.length();i++)
        {
            if(charWord1[word2[i] - 'a'] == 0)
            {
                return false;
            }
            charWord2[word2[i] - 'a']++;
        }
        vector<int> charCount1;
        vector<int> charCount2;
        for(int i=0;i<26;i++)
        {
            if(charWord1[i] != 0)
            {
                charCount1.push_back(charWord1[i]);
            }
            if(charWord2[i] != 0)
            {
                charCount2.push_back(charWord2[i]);
            }
        }
        
        sort(charCount1.begin(), charCount1.end());
        sort(charCount2.begin(), charCount2.end());
        
        if(charCount1.size() != charCount2.size())
        {
            return false;
        }
        for(int i=0;i<charCount1.size();i++)
        {
            if(charCount1[i] != charCount2[i])
            {
                return false;
            }
        }
        return true;
        
    }
};
