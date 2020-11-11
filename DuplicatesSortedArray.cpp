// Leetcode 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int prevElement = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(prevElement != nums[i])
            {
                nums[index++] = nums[i];
                prevElement = nums[i];
            }
        }
        return index;
    }
};