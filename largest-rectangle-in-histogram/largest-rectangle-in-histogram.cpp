class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        stack<int> pos;
        int maxArea = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int lastPosition = i;
            while(!st.empty() && st.top() > heights[i])
            {
                lastPosition = pos.top();
                int rectHeight = st.top();
                int rectWidth = i - lastPosition;
                int area = rectHeight*rectWidth;
                maxArea = max(area, maxArea);
                st.pop();
                pos.pop();
            }
            if(st.empty() || st.top()  < heights[i])
            {
                st.push(heights[i]);
                pos.push(lastPosition);
            }
        }
        while(!st.empty())
        {
            int area = st.top()*(heights.size()-pos.top());
            maxArea = max(area, maxArea);
            st.pop();
            pos.pop();
        }
        return maxArea;
    }
};
