class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int shortestPath = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0)
        {
            return -1;
        }
        // int rowSteps[] = {1, 0, 1, -1, 0, 1, 1, -1};
        // int colSteps[] = {0, 1, 1, 0, -1, -1, -1, 1};
        int rowSteps[] = {1, 1, 1, 0, 0,-1, -1, -1};
        int colSteps[] = {0, -1, 1, -1, 1, -1, 1, 0};
        queue<pair<pair<int,int>, int>> q;
        q.push({{0, 0}, 0});
        grid[0][0] = 1;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int shortPath = q.front().second;
            q.pop();
            // cout<<row<<col<<endl;
            if(row == m-1 && col == n-1)
            {
                shortestPath = min(shortestPath, shortPath+1);
                continue;
            }
            for(int i=0;i<8;i++)
            {
                int newRow = row + rowSteps[i];
                int newCol = col + colSteps[i];
                if(newRow < 0 || newCol < 0 || newRow > m - 1 || newCol > n -1 || grid[newRow][newCol] != 0)
                {
                    continue;
                }
                cout<<newRow<<newCol<<" ";
                grid[newRow][newCol] = 1;
                q.push({{newRow, newCol}, shortPath+1});
            }
        }
        if(shortestPath == INT_MAX)
        {
            return -1;
        }
        return shortestPath;
    }
};