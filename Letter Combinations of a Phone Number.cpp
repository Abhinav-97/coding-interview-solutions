/*https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
        {
            return ans;
        }
        map<char, string> mapping = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
      
        string characters;
        letterCombinationRecursive(ans, digits, 0, characters, mapping);
        return ans;
    }
    
    void letterCombinationRecursive(vector<string>& ans, string digits, int index, string characters, map<char,string> mapping)
    {
        if(index == digits.size())
        {
            ans.push_back(characters);
        }
        else{
            string charsForNum = mapping[digits[index]];
            for(int i=0;i<charsForNum.size();i++)
            {
                string newChar = characters + charsForNum[i];
                letterCombinationRecursive(ans, digits, index+1, newChar, mapping);
            }
        }
    }
};