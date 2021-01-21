class Solution {
public:
    void reverseString(string &s, int start, int end)
    {
        while(start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i=0;
        int right = 0;
        bool notFirstWord = false;
        while(right < s.length())
        {
            while(right < s.length() && s[right] == ' ')
            {
                right++;
            }
            if(right == s.length())
            {
                break;
            }
            if(notFirstWord)
            {
                s[i++] = ' ';
            }
            
            int left = i;
            while(right < s.length() && s[right] != ' ')
            {
                s[i] = s[right];
                i++;
                right++;
            }
            // cout<<left<<i<<" ";
            reverseString(s, left, i-1);
            notFirstWord = true;
        }
        s.resize(i);
        return s;
    }
};
