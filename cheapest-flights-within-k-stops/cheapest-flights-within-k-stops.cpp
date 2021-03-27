class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<pair<int, int>> q;
        vector<vector<pair<int,int>>> adjList(n);
        for(int i=0;i<flights.size();i++)
        {
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int cnt = 0;
        q.push({src, 0});
        int minCost = INT_MAX;
        while(cnt <= K+1 && !q.empty())
        {
            cnt++;
            int sz = q.size();
            while(sz--)
            {
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                if(cost > minCost)
                {
                    continue;
                }
                if(node == dst)
                {
                    minCost = min(minCost, cost);
                    continue;
                }
                for(auto it=adjList[node].begin();it!=adjList[node].end();++it)
                {
                    q.push({it->first, cost+it->second});
                }
                
            }
        }
        if(minCost == INT_MAX)
        {
            return -1;
        }
        return minCost;
    }
};