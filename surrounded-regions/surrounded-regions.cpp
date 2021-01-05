class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)
        {
            return;
        }
        int n = board[0].size();
        if(n == 0)
        {
            return;
        }
        bool visited[m][n];
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++)
        {
            if(board[i][0] == 'O')
            {
                visited[i][0] = true;
                q.push(make_pair(i, 0));
            }
            if(board[i][n-1] == 'O')
            {
                visited[i][n-1] = true;
                q.push(make_pair(i, n-1));
            }
        }
        
        for(int j=0;j<n;j++)
        {
            if(board[0][j] == 'O')
            {
                visited[0][j] = true;
                q.push(make_pair(0, j));
            }
            if(board[m-1][j] == 'O')
            {
                visited[m-1][j] = true;
                q.push(make_pair(m-1, j));
            }
        }
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
          
            q.pop();
            if(row-1 >= 0 && board[row-1][col] == 'O' && !visited[row-1][col])
            {
                q.push(make_pair(row-1, col));
                visited[row-1][col] = true;
            }
            if(col-1 >= 0 && board[row][col-1] == 'O' && !visited[row][col-1])
            {
                q.push(make_pair(row, col-1));
                visited[row][col-1] = true;
            }
            if(row+1 < m && board[row+1][col] == 'O' && !visited[row+1][col])
            {
                q.push(make_pair(row+1, col));
                visited[row+1][col] = true;
