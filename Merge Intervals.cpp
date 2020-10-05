/*
Merge Interval Leetcode 56 
https://leetcode.com/problems/merge-intervals/
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int> > ans;
        if(intervals.empty())
        {
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
        //  if intervals dont overlap push them            
            if(end < intervals[i][0])
            {
                ans.push_back({start, end});
                
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // else merge the intervals
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};