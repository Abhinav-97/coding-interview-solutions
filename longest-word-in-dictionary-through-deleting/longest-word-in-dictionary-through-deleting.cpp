bool comparator(string A, string B)
{
    if(A.length() == B.length())
    {
        return A < B;
    }
    return A.length() > B.length();
}
class Solution {
    
public:
    bool isSubsequence(string X, string Y)
    {
        int j=0;
        int i=0;
        while(i < X.length() && j < Y.length())
        {
            if(X[i] == Y[j])
            {
                j++;
            }
            i++;
        }
        return j == Y.length();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), comparator);
        for(int i=0;i<d.size();i++)
        {
            if(isSubsequence(s, d[i]))
            {
                return d[i];
            }
        }
        return "";
    }
};