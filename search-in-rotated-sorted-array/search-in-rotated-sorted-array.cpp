class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(mid < nums.size()-1 && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            if(nums[low] <= nums[mid])
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return 0;
    }
    int binarySearch(vector<int>& arr, int low, int high, int target)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid] == target)
            {
                return mid;
            }
            if(target > arr[mid])
            {
                low = mid+1;
            }
            else if(target < arr[mid])
            {
                high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivot(nums);
        if(nums[pivotIndex] == target)
        {
            return pivotIndex;
        }
        int leftFound = binarySearch(nums, 0, pivotIndex-1, target);
        if(leftFound != -1)
        {
            return leftFound;
        }
        return binarySearch(nums, pivotIndex+1, nums.size()-1, target);
    }
};
