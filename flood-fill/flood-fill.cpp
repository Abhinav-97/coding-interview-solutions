class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        helper(image, sr, sc, -1, newColor);
        return image;
    }
    
    void helper(vector< vector<int> >& image, int sr, int sc, int previousColor, int newColor)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
        {
            return;
        }
        
        if(previousColor != -1 && image[sr][sc] != previousColor)
        {
            return;
        }
        if(image[sr][sc] == newColor)
        {
            return;
        }
        int prevColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        helper(image, sr, sc-1, prevColor, newColor); // left
        helper(image, sr-1, sc, prevColor, newColor); // top
        helper(image, sr, sc+1, prevColor, newColor); // right
        helper(image, sr+1, sc, prevColor, newColor); // bottom
        
    }
};
