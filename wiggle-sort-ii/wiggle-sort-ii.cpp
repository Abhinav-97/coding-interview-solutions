class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> res(nums.size());
        int greaterIdx = 1;
        int smallerIdx = 0;
        int mid = nums.size()/2;
        for(int i=0;i<mid;i++)
        {
            res[greaterIdx] = nums[i];
            greaterIdx += 2;
        }
        for(int i=mid;i<nums.size();i++)
        {
            res[smallerIdx] = nums[i];
            smallerIdx += 2;
        }
        for(int i=0;i<res.size();i++)
        {
            nums[i] = res[i];
        }
    }
};
