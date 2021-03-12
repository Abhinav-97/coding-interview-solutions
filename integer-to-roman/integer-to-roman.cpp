class Solution {
public:
    string intToRoman(int num) {
        // map<string, int> romanToIntMap;
        int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
         map<int, string> romanToIntMap = {{1000, "M"},
                         {900, "CM"},
                         {500, "D"},
                         {400, "CD"},
                         {100, "C"},
                         {90, "XC"},
                         {50, "L"},
                         {40, "XL"},
                         {10, "X"},
                         {9, "IX"},
                         {5, "V"},
                         {4, "IV"},
                         {1, "I"}};
        string ans = "";
        for(int i=0;i<13;i++)
        {
            if((num/numbers[i]) > 0)
            {
                int numTimes = num/numbers[i];
                for(int k=0;k<numTimes;k++)
                {
                    ans += romanToIntMap[numbers[i]];
                }
                num = num - numTimes*numbers[i];
            
            }
        }
        return ans;
    }
};