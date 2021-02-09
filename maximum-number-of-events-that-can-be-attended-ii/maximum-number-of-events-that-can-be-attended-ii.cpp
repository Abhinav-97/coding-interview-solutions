struct Info
    {
        int startDay;
        int endDay;
        int val;
    };
    bool comparator(Info i1, Info i2)
    {
        return i1.startDay < i2.startDay;
    }
class Solution {
public:
    
    int maxValue(vector<vector<int>>& events, int k) {
        vector<Info> infos;
        vector<vector<int>> dp(events.size(), vector<int>(k+1, -1));
        for(int i=0;i<events.size();i++)
        {
            Info info;
            info.startDay = events[i][0];
            info.endDay = events[i][1];
            info.val = events[i][2];
            infos.push_back(info);
        }
        sort(infos.begin(), infos.end(), comparator);
        return helper(infos, 0, k, dp);
    }
    
    int helper(vector<Info> &infos, int index, int k, vector<vector<int>> &dp)
    {
        if(k == 0)
        {
            return 0;
        }
        if(index == infos.size())
        {
            return 0;
        }
        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }
        int idx = index+1;
        while(idx < infos.size())
        {
            if(infos[index].endDay < infos[idx].startDay)
            {
                break;
            }
            idx++;
        }
        // cout<<index<<" "<<idx<<endl;
        int take = helper(infos, idx, k-1, dp) + infos[index].val;
        int notTake = helper(infos, index+1, k, dp);
        
        return dp[index][k] = max(take, notTake);
    }
};