// C++ solution for https://www.interviewbit.com/problems/black-shapes/
//  Reference https://www.geeksforgeeks.org/find-number-of-islands/


int rowSteps[] = {0, 1, -1, 0};
int colSteps[] = {1, 0, 0, -1};

bool isPossible(int i, int j, int n, int m)
{
    if(i<n && j<m && i>=0 && j>=0){
        return true;
    }
    else{
        return false;
    }
}
void DFS(vector<string> A, int n, int m, int row, int col,  vector< vector<bool> > &visited)
{
    visited[row][col] = true;
    for(int k=0;k<4;k++)
    {
        int newRow = row + rowSteps[k];
        int newCol = col + colSteps[k];
        if(isPossible(newRow, newCol, n, m) && A[newRow][newCol] == 'X' && !visited[newRow][newCol])
        {
            DFS(A, n, m, newRow, newCol, visited);
        }
    }
    
}
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector< vector<bool> > visited;
    for(int i=0;i<n;i++)
    {
        vector<bool> b;
        for(int j=0;j<m;j++)
        {
            b.push_back(false);
        }
        visited.push_back(b);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {

            if(A[i][j]=='X' && visited[i][j] == false){
                ans ++;
                DFS(A, n, m, i, j, visited);
            }
        }
    }
    return ans;
}