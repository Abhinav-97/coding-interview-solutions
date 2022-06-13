class Solution {
public:
    void bfs(int src, vector<vector<int>>& isConnected)
    {
        vector<bool> visited(isConnected.size(), false);
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int node=0;node<isConnected.size();node++)
            {
                if(isConnected[curr][node] == 1)
                {
                    isConnected[curr][node] = 0;
                    if(visited[node] == false)
                    {
                        visited[node] = true;
                        q.push(node);
                    }
                }
                
               
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num_provinces = 0;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j] == 1)
                {
                    num_provinces++;
                    bfs(i, isConnected);
                }
            }
        }
        return num_provinces;
        
    }
};