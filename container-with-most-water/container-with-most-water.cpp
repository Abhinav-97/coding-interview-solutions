class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;
        while(left <= right)
        {
            int length = min(height[left], height[right]);
            int breadth = (right - left);
            maxArea = max(maxArea, length*breadth);
            if(height[left] < height[right])
            {
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};