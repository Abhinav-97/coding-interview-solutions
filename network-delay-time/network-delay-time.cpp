class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int src) {
        vector< vector<pair<int, int> > >graph(N+1);
        
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back(make_pair(times[i][2], times[i][1]));
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        vector<int> distance(N+1, INT_MAX);
        
        distance[src] = 0;
        minH.push({0, src});
        
        while(!minH.empty())
        {
            int currNode = minH.top().second;
            minH.pop();
            for(auto it = graph[currNode].begin();it!=graph[currNode].end();++it)
            {
                int weight = it->first;
                int edgeNode = it->second;
                if(distance[currNode] + weight < distance[edgeNode])
                {
                    distance[edgeNode] = distance[currNode] + weight;
                    minH.push({distance[edgeNode], edgeNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<distance.size();i++)
        {
            ans = max(ans, distance[i]);
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
