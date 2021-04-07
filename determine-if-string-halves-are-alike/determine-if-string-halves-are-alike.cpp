class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowels1 = 0;
        int vowels2 = 0;
        for(int i=0;i<s.length();i++)
        {
            char ch = tolower(s[i]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                if(i < s.length()/2)
                {
                    vowels1++;
                }
                else{
                    vowels2++;
                }
            }
        }
        return vowels1 == vowels2;
        
    }
};