class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num > 0)
        {
            if(num % 2 == 0)
            {
                num = num/2;
            }
            else if(num % 2 == 1)
            {
                num -= 1;
            }
            ans++;
        }
        return ans;
    }
};