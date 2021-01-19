class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.length()][s.length()];
        memset(dp, false, sizeof(dp));
        int len = 0;
        int startIndex = 0;
        for(int i=0;i<s.length();i++)
        {
            dp[i][i] = true;
            len = 1;
            startIndex = i;
        }
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                len = 2;
                startIndex = i;
            }
        }
        for(int k=3;k<=s.length();k++)
        {
            for(int i=0;i<s.length()-k+1;i++)
            {
               int j = i + k - 1;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    len = k;
                    dp[i][j] = true;
                    startIndex = i;
                }
            }
        }
        string ans = "";
        for(int i=0;i<len;i++)
        {
            ans += s[startIndex++];
        }
        return ans;
    }
};
