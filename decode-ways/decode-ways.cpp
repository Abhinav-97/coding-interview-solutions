class Solution {
public:
    int numDecodings(string s) {
        int dp[s.length()+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if(s[0] == '0')
        {
            dp[1] = 0;
        }
        else{
            dp[1] = 1;
        }
        for(int i=2;i<=s.length();i++)
        {
            int onesPlace = s[i-1] - '0';
            cout<<onesPlace;
            if(onesPlace >= 1 && onesPlace <= 9)
            {
                dp[i] += dp[i-1];
            }
            int tensPlace = (s[i-2]-'0')*10 + onesPlace;
            cout<<tensPlace<<endl;
            if(tensPlace >= 10 && tensPlace <= 26)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }
};