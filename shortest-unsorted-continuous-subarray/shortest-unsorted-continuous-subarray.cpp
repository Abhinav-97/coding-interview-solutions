class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        bool sorted = false;
        int startElement = INT_MAX;
        int endElement = INT_MIN;
        bool flag = false;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < nums[i-1])
            {
                flag = true;

            }
            if(flag)
            {
                startElement = min(startElement, nums[i]);
            }
        }
        flag = false;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i] > nums[i+1])
            {
                flag = true;
            }
            if(flag)
            {
                endElement = max(endElement, nums[i]);
            }
        }
        int l,r;
        for(l=0;l<nums.size();l++)
        {
            if(startElement < nums[l])
            {
                break;
            }
        }
        for(r=nums.size()-1;r>=0;r--)
        {
            if(endElement > nums[r])
            {
                break;
            }
        }
        if(r-l < 0)
        {
            return 0;
        }
        return r-l+1;
        
    }
};