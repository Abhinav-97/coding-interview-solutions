class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int score = 0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == '(')
            {
                st.push(score);
                score = 0;
            }
            else{
                score = st.top() + max(score*2, 1);
                st.pop();
            }
        }
        return score;
    }
};