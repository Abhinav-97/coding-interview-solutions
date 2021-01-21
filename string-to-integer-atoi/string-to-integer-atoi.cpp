class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        // int idx = 0;
        int i = 0;
        while(i < s.length() && s[i] == ' ')
        {
            i++;
        }
        bool neg = false;
        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i] == '-')
            {
                neg = true;
            }
            i++;
        }
        while(i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            if(ans > INT_MAX/10 || ans == INT_MAX/10 && s[i] - '0' > INT_MAX%10)
            {
                if(neg)
                {
                    return INT_MIN;
                }
                return INT_MAX;
            }
            ans = ans*10 + (s[i] - '0');
            i++;
        }
        if(neg)
        {
            return -1*ans;
        }
        return ans;
    }
};
