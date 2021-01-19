class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        bool neg = false;
        if(dividend < 0 || divisor < 0)
        {
            neg = true;
        }
        if(dividend < 0 && divisor < 0)
        {
            neg = false;
        }
        int i = 0;
        long long int ans = 0;
        long long int a = abs(dividend);
        long long int b = abs(divisor);
        while(a >= b)
        {
            int x = 0;
            while(a - (b<<1<<x) >=0)
            {
                x++;
            }
            ans += 1<<x;
            a -= b<<x;
        }
        if(neg)
        {
            return -ans;
        }
        return ans;
    }
};
