class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int dp[A.size()][501][2];
        memset(dp, 0, sizeof(dp));
        int ans = INT_MIN;
        for(int i=1;i<A.size();i++)
        {
            
            for(int j=0;j<i;j++)
            {
                int diff = A[i] - A[j];
                if(diff < 0)
                {
                    dp[i][abs(diff)][0] = max(dp[i][abs(diff)][0], dp[j][abs(diff)][0]+1);
                    ans = max(ans, dp[i][abs(diff)][0]);
                }
                else{
                    dp[i][abs(diff)][1] = max(dp[i][abs(diff)][1], dp[j][abs(diff)][1]+1);
                    ans = max(ans, dp[i][abs(diff)][1]);
                }
            }
        }
        return ans+1;
        
    }
};