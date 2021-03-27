class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int dp[matrix.size()][matrix[0].size()];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0] == '1')
            {
                dp[i][0] = 1;
            }
            ans = max(ans, dp[i][0]);
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[0][j] == '1')
            {
                dp[0][j] = 1;
            }
            ans = max(ans, dp[0][j]);
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if(matrix[i-1][j] == '1' && matrix[i][j-1] == '1' && matrix[i-1][j-1] == '1')
                    {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};