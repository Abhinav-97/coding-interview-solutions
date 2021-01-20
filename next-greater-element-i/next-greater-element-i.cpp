class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> greaterElementMap;
        stack<int> st;
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty() && st.top() < nums2[i])
            {
                greaterElementMap[st.top()] = nums2[i];
                st.pop();
            }
            greaterElementMap[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(greaterElementMap[nums1[i]]);
        }
        return ans;
    }
};
