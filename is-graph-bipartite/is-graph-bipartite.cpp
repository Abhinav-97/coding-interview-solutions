class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>>adjList(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adjList[i].push_back(graph[i][j]);
                // adjList[graph[i][j]].push_back(i);
            }
        }
        vector<int> color(graph.size(), -1);
        color[0] = 0;
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            q.push(i);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(auto it=adjList[u].begin();it!=adjList[u].end();++it)
                {   cout<<(*it)<<" ";
                    if(color[*it] != -1 && color[*it] == color[u])
                    {
                        return false;
                    }
                    if(color[*it] == -1)
                    {
                        q.push(*it);
                        color[*it] = 1 - color[u];
                    }
                }
                cout<<endl;
            }
        }
        return true;
        
    }
};