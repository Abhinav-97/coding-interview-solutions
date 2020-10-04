/*
Rotate Image Leetcode 48
https://leetcode.com/problems/rotate-image/

Method: for Clockwise roattion we do transpose and then Reverse rows
Example 
                Transpose       Reverse Row
     1 2 3        1 4 7         7 4 1

     4 5 6 -----> 2 5 8  -----> 8 5 2
           ----->        -----> 
     7 8 9        3 6 9         9 6 3


Similarly for Anti Clock wise rotation reverse rows and then transpose.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i < j){
                    
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        for(int i = 0;i<m;i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};