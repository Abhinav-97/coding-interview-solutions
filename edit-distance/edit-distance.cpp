class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=word1.length();i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=word2.length();j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                if(word1[i-1] != word2[j-1])
                {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
    
    int helper(string word1, string word2, int m, int n)
    {
        if(n == 0)
        {
            return m;
        }
        if(m == 0)
        {
            return n;
        }
        if(word1[m-1] == word2[n-1])
        {
            return helper(word1, word2, m-1, n-1);
        }
        
        return 1 + min(helper(word1, word2, m-1, n-1), min(helper(word1, word2, m-1, n), helper(word1, word2, m, n-1)));
    }
        
};