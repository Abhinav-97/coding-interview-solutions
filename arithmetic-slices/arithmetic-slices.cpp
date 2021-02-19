class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 2)
        {
            return 0;
        }
        int dp[A.size()];
        int ans;
        memset(dp, 0, sizeof(dp));
        for(int i=2;i<A.size();i++)
        {
            if(A[i] - A[i-1] == A[i-1] - A[i-2])
            {
                dp[i] = dp[i-1] + 1;
                cout<<dp[i]<<endl;
                ans += dp[i];
            }
        }
        return ans;
    }
};