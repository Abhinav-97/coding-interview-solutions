class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openBrackets = 0;
        string firstPass = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')')
            {
                if(openBrackets == 0)
                {
                    continue;
                }
                openBrackets--;

            }
            else if(s[i] == '(')
            {
                openBrackets++;
            }
            firstPass += s[i];
        }
        string ans = "";

        for(int i=firstPass.length()-1;i>=0;i--)
        {
            if(firstPass[i] == '(' && openBrackets > 0)
            {
                openBrackets--;
                continue;
            }
            ans += firstPass[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};