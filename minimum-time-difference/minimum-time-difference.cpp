class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        unordered_map<int, bool> timesMap;
        for(int i=0;i<timePoints.size();i++)
        {
            int hour = 0;
            hour += (timePoints[i][0]-'0')*10;
            hour += (timePoints[i][1]-'0');
            
            int minutes = (timePoints[i][3]-'0')*10;
            minutes += (timePoints[i][4] - '0');
            
            minutes += (hour*60);
            
            times.push_back(minutes);
            if(timesMap.find(minutes) != timesMap.end())
            {
                return 0;
            }
            timesMap[minutes] = true;
        }
        int minDiff = INT_MAX;
        for(int i=0;i<times.size();i++)
        {
            int cnt = 1;
            int minute = times[i]+1;
            
            while(timesMap.find(minute%(24*60)) == timesMap.end())
            {
                cnt++;
                minute++;
            }
            minDiff = min(minDiff, cnt);
        }
        return minDiff;
        
    }
};