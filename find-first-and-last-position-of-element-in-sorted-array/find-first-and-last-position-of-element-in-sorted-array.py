class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        low = 0
        hi = len(nums) - 1
        while low <= hi:
       
            mid = low + (hi - low)//2
            if(nums[mid] == target):
                endIndex = mid
                startIndex = mid
                while startIndex > 0 and nums[startIndex-1] == nums[mid]:
                    startIndex -= 1
                while endIndex < len(nums)-1 and nums[endIndex+1] == nums[mid]:
                    endIndex += 1
                    
                return [startIndex, endIndex]
                
            elif nums[mid] < target:
                low = mid+1
            else:
                hi = mid-1
        
        return [-1,-1]
        
                    
            
        