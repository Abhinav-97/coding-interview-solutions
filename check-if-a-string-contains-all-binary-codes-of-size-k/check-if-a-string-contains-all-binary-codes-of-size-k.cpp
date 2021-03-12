class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k)
        {
            return false;
        }
        bool visited[1<<k];
        memset(visited, false, sizeof(visited));
        int numCodes = 0;
        for(int i=0;i<s.length()-k+1;i++)
        {
            string substring = s.substr(i, k);
            // cout<<substring<<endl;
            int decimalVal = 0;
            int multiplyVal = 1;
            for(int j=substring.length()-1;j>=0;j--)
            {
                decimalVal += (substring[j] - '0')*multiplyVal;
                multiplyVal = 2*multiplyVal;
                
            }
            // cout<<decimalVal<<endl;
            if(visited[decimalVal] == false)
            {
                visited[decimalVal] = true;
                numCodes++;
                if(numCodes == 1<<k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};