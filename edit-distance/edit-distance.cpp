class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word2.length();i++)
        {
            dp[0][i] = i;
        }
        for(int j=0;j<=word1.length();j++)
        {
            dp[j][0] = j;
        }
        
        for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
    
    int minDistanceRec(string word1, string word2, int n, int m)
    {
        if(n == 0)
        {
            return m;
        }
        if(m == 0)
        {
            return n;
        }
        if(word1[n-1] == word2[m-1])
        {
            return minDistanceRec(word1, word2, n-1, m-1);
        }
        return 1 + min(minDistanceRec(word1, word2, n, m-1), // insert
                      min(minDistanceRec(word1, word2, n-1, m), // remove
                      minDistanceRec(word1, word2, n-1, m-1))); // replace
    }
};
