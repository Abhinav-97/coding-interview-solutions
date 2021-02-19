class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string firstPass = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                    firstPass += s[i];
                }
            }
            else if(s[i] == '(')
            {
                st.push(s[i]);
                firstPass += s[i];
            }
            else{
                firstPass += s[i];
            }
        }
        if(st.empty())
        {
            return firstPass;
        }
        string ans = "";
        while(!st.empty())
        {
            st.pop();
        }
        reverse(firstPass.begin(), firstPass.end());
        for(int i=0;i<firstPass.length();i++)
        {
            if(firstPass[i] == '(')
            {
                if(!st.empty())
                {
                    st.pop();
                    ans += firstPass[i];
                }
            }
            else if(firstPass[i] == ')')
            {
                st.push(firstPass[i]);
                ans += firstPass[i];
            }
            else{
                ans += firstPass[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};