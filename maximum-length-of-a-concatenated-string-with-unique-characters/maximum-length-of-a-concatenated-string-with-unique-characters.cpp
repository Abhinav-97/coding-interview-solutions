class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = INT_MIN;
        helper(arr, 0, "", ans, 0);
        if(ans == INT_MIN)
        {
            return 0;
        }
        return ans;
    }
    int isUnique(string str)
    {
        int count[26] = {0};
        for(int i=0;i<str.length();i++)
        {
            if(count[str[i] - 'a'] > 0)
            {
                return -1;
            }
            count[str[i] - 'a']++;
        }
        return str.length();
    }
    void helper(vector<string> &arr, int index, string resString, int &maxLen, int currentLen)
    {
        if(index == arr.size())
        {
            return;
        }
​
        if(isUnique(resString + arr[index]) > -1)
        {
            int newLength = currentLen+arr[index].length();
            maxLen = max(maxLen, newLength);
            helper(arr, index+1, resString + arr[index], maxLen, newLength);
        }
        helper(arr, index+1, resString, maxLen, currentLen);
            
        
        
    }
};
