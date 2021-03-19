class Solution {
public:
    void dfs(vector<vector<int>> &rooms, bool visited[], int src)
    {
        visited[src] = true;
        for(int i=0;i<rooms[src].size();i++)
        {
            if(!visited[rooms[src][i]])
            {
                dfs(rooms, visited,rooms[src][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[rooms.size()];
        memset(visited, false, sizeof(visited));
        dfs(rooms, visited, 0);
        for(int i=0;i<rooms.size();i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};