class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact;
        fact.push_back(1);
        for(int i=1;i<=9;i++)
        {
            fact.push_back(fact[i-1]*i);
        }
        string ans = "";
        string digits = "123456789";
        k--;
        for(int i=n;i>0;i--)
        {
            int index = k/fact[i-1];
            k = k%fact[i-1];
            ans += digits[index];
            digits.erase(digits.begin()+index);
        }
        return ans;
    }
};
