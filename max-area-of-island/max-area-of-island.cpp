class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
        {
            return 0;
        }
        int n = grid[0].size();
        if(n == 0)
        {
            return 0;
        }
        queue<pair<int, int>> q;
        int maxArea = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0;
                    grid[i][j] = 0;
                    q.push(make_pair(i, j));
                    while(!q.empty())
                    {
                        area++;
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        if(row - 1 >= 0 && grid[row-1][col] == 1)
                        {
                            q.push(make_pair(row-1, col));
                            grid[row-1][col] = 0;
                        }
                        if(row+1 < m && grid[row+1][col] == 1)
                        {
                            q.push(make_pair(row+1, col));
                            grid[row+1][col] = 0;
                        }
                        if(col-1 >=0 && grid[row][col-1] == 1)
                        {
                            q.push(make_pair(row, col-1));
                            grid[row][col-1] = 0;
                        }
                        if(col+1 < n && grid[row][col+1] == 1)
                        {
                            q.push(make_pair(row, col+1));
                            grid[row][col+1] = 0;
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};