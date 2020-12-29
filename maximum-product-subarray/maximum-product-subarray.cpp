class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int current = nums[i];
            int tempMax = maxProduct*nums[i];
            int tempMin = minProduct*nums[i];
            
            minProduct = min(current, min(tempMax, tempMin));
            maxProduct = max(current, max(tempMax, tempMin));
            
            ans = max(ans, maxProduct);
        }
        return ans;
    }
    
};
