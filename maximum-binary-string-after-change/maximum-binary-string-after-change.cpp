class Solution {
public:
    string maximumBinaryString(string binary) {
        int startingOnes = 0;
        for(int i=0;i<binary.length();i++)
        {
            if(binary[i] == '0')
            {
                break;
            }
            startingOnes++;
        }
        string ans;
        for(int i=0;i<startingOnes;i++)
        {
            ans += '1';
        }
        int numOnes = 0;
        int numZeros = 0;
        for(int i=startingOnes;i<binary.length();i++)
        {
            if(binary[i] == '0')
            {
                numZeros++;
            }
            else{
                numOnes++;
            }
        }
        for(int i=0;i<numZeros-1;i++)
        {
            ans += '1';
        }
        if(numZeros > 0)
        {
            ans += '0';
        }
        for(int i=0;i<numOnes;i++)
        {
            ans += '1';
        }
        return ans;
        
    }
};
