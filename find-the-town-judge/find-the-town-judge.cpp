class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int> judgeTrust;
        unordered_map<int,int> trustMap;
        for(int i=1;i<=N;i++)
        {
            trustMap[i] = 0;
            judgeTrust[i] = 0;
        }
        for(int i=0;i<trust.size();i++)
        {
            trustMap[trust[i][0]]++;
            judgeTrust[trust[i][1]]++;
        }
        for(auto it=trustMap.begin();it!=trustMap.end();++it)
        {
            auto itr = judgeTrust.find(it->first);
            if(itr != judgeTrust.end())
            {
                if(it->second == 0 && itr->second == N-1)
                {
                    return it->first;
                }
            }
        }
        return -1;
    }
};
