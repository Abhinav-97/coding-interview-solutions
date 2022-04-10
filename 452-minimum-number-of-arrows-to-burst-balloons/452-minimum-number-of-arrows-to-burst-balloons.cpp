class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int num_arrows = 0;
        int i=0;
        // for(int i=0;i<points.size();i++)
        // {
        //     cout<<points[i][0]<<" "<<points[i][1]<<endl;
        // }
        while(i < points.size()-1)
        {
            cout<<i<<endl;;
            int j=i+1;
            while(j < points.size() && points[i][1] >= points[j][0])
            {
                j++;
            }
            i=j;
            num_arrows++;
        }
        if(i == points.size()-1)
        {
            num_arrows++;
        }
        return num_arrows;
    }
};