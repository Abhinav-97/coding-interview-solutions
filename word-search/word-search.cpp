class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    if(helper(board, i, j, 1, word, visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, int row, int col, int index, string word, vector<vector<bool>> &visited)
    {
        if(index == word.length())
        {
            return true;
        }
        visited[row][col] = true;
        if(row+1 < board.size() && !visited[row+1][col] &&board[row+1][col] == word[index])
        {
            if(helper(board, row+1, col, index+1, word, visited))
            {
                return true;
            }
        }
        if(col+1 < board[0].size() && !visited[row][col+1] && board[row][col+1] == word[index])
        {
            if(helper(board, row, col+1, index+1, word, visited))
            {
                return true;
            }
        }
        if(row-1 >= 0 && !visited[row-1][col] && board[row-1][col] == word[index])
        {
            if(helper(board, row-1, col, index+1, word, visited))
            {
                return true;
            }
        }
        if(col-1 >= 0 && !visited[row][col-1] && board[row][col-1] == word[index])
        {
            if(helper(board, row, col-1, index+1, word, visited))
            {
                return true;
            }
        }
        visited[row][col] = false;
        return false;
        
    }
};
