class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> topToBottom;
        vector<int> leftToRight;
        for(int i=0;i<grid.size();i++)
        {
            int maxElement = INT_MIN;
            for(int j=0;j<grid[0].size();j++)
            {
                maxElement = max(maxElement, grid[i][j]);
            }
            leftToRight.push_back(maxElement);
        }
        for(int i=0;i<grid[0].size();i++)
        {
            int maxElement = INT_MIN;
            for(int j=0;j<grid.size();j++)
            {
                // cout<<grid[i][j]<<" ";
                maxElement = max(maxElement, grid[j][i]);
            }
            topToBottom.push_back(maxElement);
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                // cout<<grid[i][j]<<" ";
                if(grid[i][j] == leftToRight[i] || grid[i][j] == topToBottom[j])
                {
                    continue;
                }
                ans += min(leftToRight[i], topToBottom[j]) - grid[i][j];
            }
        }
        return ans;
    }
};