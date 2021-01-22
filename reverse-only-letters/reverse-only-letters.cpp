class Solution {
public:
    bool isLetter(char c)
    {
        if((c - 'a' >=0 && c-'a' < 26)
          || (c-'A' >=0 && c-'A' < 26))
        {
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string S) {
        int left = 0;
        int right = S.length()-1;
        while(left <= right)
        {
            if(isLetter(S[left]) && isLetter(S[right]))
            {
                swap(S[left], S[right]);
                left++;
                right--;
            }
            else{
                if(!isLetter(S[left]))
                {
                    left++;
                }
                if(!isLetter(S[right]))
                {
                    right--;
                }
            }
        }
        return S;
    }
};
