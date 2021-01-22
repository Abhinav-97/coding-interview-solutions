class Solution {
public:
    const int BOARD_SIZE = 8;
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int row = king[0];
        int col = king[1];
        vector<vector<int> >ans;
        map<pair<int,int>, bool> queenMap;
        for(int i=0;i<queens.size();i++)
        {
            queenMap[make_pair(queens[i][0], queens[i][1])] = true;
        }
        // top
        int r = row;
        int c = col;
        while(r-1 >= 0)
        {
            if(queenMap.find(make_pair(r-1, c)) != queenMap.end())
            {
                vector<int> v;
                v.push_back(r-1);
                v.push_back(c);
                ans.push_back(v);
                break;
            }
            r -= 1;
        }
        //left
        r = row;
        c = col;
        while(c-1 >= 0)
        {
            if(queenMap.find(make_pair(r, c-1)) != queenMap.end())
            {
                vector<int> v;
                v.push_back(r);
                v.push_back(c-1);
                ans.push_back(v);
                break;
            }
            c -= 1;
        }
        // bottom
