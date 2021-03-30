class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left <= right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            
            if(leftMax <= rightMax)
            {
                ans += leftMax - height[left];
                left++;
            }
            else{
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};