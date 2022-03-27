class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ans;
        if(nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            int left  = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                if(nums[i]+nums[left]+nums[right] == 0)
                {
                    
                    ans.push_back({nums[i], nums[left], nums[right]});
                     while(left < nums.size()-1 && nums[left]==nums[left+1])
                    {
                        left++;
                    }
                    while(right > 0 && nums[right]==nums[right-1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                    
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else{
                    right--;
                }
               
                
            }
            while((i < nums.size()-1) && (nums[i] == nums[i+1]))
            {
                i++;
            }
            
        }
        return ans;
    }
};