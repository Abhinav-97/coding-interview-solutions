class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;
        while(j < chars.size())
        {
            int count=1;
            // chars[i] = chars[j];
            // i++;
            while(j < chars.size()-1 && chars[j]==chars[j+1])
            {
                count++;
                j++;
                
            }
            chars[i] = chars[j];
            i++;
            j++;
            if(count == 1)
            {
                continue;
            }
            string count_str = to_string(count);
            for(int k=0;k<count_str.length();k++)
            {
                chars[i] = count_str[k];
                i++;
            }
        }
        chars.resize(i);
        return chars.size();
    }
};