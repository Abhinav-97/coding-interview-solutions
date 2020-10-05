/*Leetcode 179 Largest Number
https://leetcode.com/problems/largest-number/
*/
class Solution {
public:
    static bool comp(int a, int b)
    {
        string stringA = to_string(a);
        string stringB = to_string(b);
        return stringA + stringB > stringB + stringA;
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(), comp);
        if(nums[0] == 0){
            return "0";
        }
        string ans = "";
        for(int i=0;i<nums.size();i++)
        {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};