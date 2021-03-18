class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool pos = true;
        bool neg = false;
        int ans = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(pos)
            {
                if(nums[i] - nums[i-1] > 0)
                {
                    cout<<nums[i];
                    ans++;
                    pos = false;
                    neg = true;
                }
            }
            else if(neg)
            {
                if(nums[i] - nums[i-1] < 0)
                {
                    ans++;
                    pos = true;
                    neg = false;
                }
            }
        }
        int secondans = 1;
        neg = true;
        pos = false;
        for(int i=1;i<nums.size();i++)
        {
            if(neg)
            {
                if(nums[i] - nums[i-1] < 0)
                {
                    secondans++;
                    pos = true;
                    neg = false;
                }
            }
            else if(pos)
            {
                if(nums[i] - nums[i-1] > 0)
                {
                    secondans++;
                    pos = false;
                    neg = true;
                }
            }
        }
        return max(ans, secondans);
    }
};