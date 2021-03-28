class Solution {
public:
    int dp[4194303] = {};
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0)
        {
            return true;
        }
        int sum = (maxChoosableInteger * (maxChoosableInteger+1))/2;
        
        if(sum <desiredTotal) return false;
        
        int ans = canIWinRec(maxChoosableInteger, desiredTotal, 0, true);
        if(ans == 1)
        {
            return true;
        }
        return false;
    }
    
    bool checkIfBitSet(int track, int pos)
    {
       return ((track>>pos) & 1)==1;
    }
    
    int canIWinRec(int maxChoosableInteger, int desiredTotal, int track, bool player)
    {
        if(desiredTotal <= 0)
        {
            if(player){
                return dp[track] = -1;
            }
            else{
                return dp[track] = 1;
            }
        }
        if(dp[track] != 0)
        {
            return dp[track];
        }
        int ans;
        if(player)
        {
            ans = INT_MIN;
            for(int i=1;i<=maxChoosableInteger;i++)
            {
                
                if(!checkIfBitSet(track, i))
                {
                    
                    ans = max(ans, canIWinRec(maxChoosableInteger, desiredTotal- i, track | (1<<i), !player));
                    if(ans == 1) return dp[track] = 1;
                }
            }
        }
        else
        {
            ans = INT_MAX;
            for(int i=1;i<=maxChoosableInteger;i++)
            {
                
                
                if(!checkIfBitSet(track, i))
                {
                    
                    ans = min(ans, canIWinRec(maxChoosableInteger, desiredTotal- i, track | (1<<i), !player));
                    if(ans == -1) return dp[track] -1;
                }
            }
        }
        return dp[track] = ans;
    }
};