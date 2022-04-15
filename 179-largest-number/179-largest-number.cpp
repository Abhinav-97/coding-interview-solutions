bool cmp(string a, string b)
{
    int i=0;
    int j=0;
    // cout<<a<<b;
    // while(i < a.length() && j < b.length())
    // {
    return a+b > b+a;
    // }
    
    return a.length() < b.length();
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> arr(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            arr[i] = to_string(nums[i]);
            // cout<<arr[i][0]-'0';
        }
        string ans="";
        sort(arr.begin(), arr.end(), cmp);
        for(int i=0;i<arr.size();i++)
        {
            ans += arr[i];
        }
        if(ans[0] == '0')
        {
            return "0";
        }
        return ans;
        
    }
};