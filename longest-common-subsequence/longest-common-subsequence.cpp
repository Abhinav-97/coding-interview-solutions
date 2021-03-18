class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.length()+1][text2.length()+1];
        for(int i=0;i<=text1.length();i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<=text2.length();i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=text1.length();i++)
        {
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
    int lcs(string text1, string text2, int m, int n)
    {
        if(n == 0 || m == 0)
        {
            return 0;
        }
        if(text1[m-1] == text2[n-1])
        {
            return 1 + lcs(text1, text2, m-1, n-1);
        }
        return max(lcs(text1, text2, m, n-1), lcs(text1, text2, m-1, n));
    }
};