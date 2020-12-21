class Solution {
public:
    bool isStringPartition(string s)
    {
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i] != s[s.length()-i-1])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector< vector<string> > ans;
        vector<string> partition;
        partitionRec(s, ans, partition);
        return ans;
    }
    
    void partitionRec(string s, vector< vector<string> > &ans, vector<string> &partition)
    {
        if(isStringPartition(s))
        {
            partition.push_back(s);
            ans.push_back(partition);
            partition.pop_back();
        }
        for(int i=1;i<s.length();i++)
        {
            string substring = s.substr(0,i);
            if(isStringPartition(substring))
            {
                cout<<substring<<" ";
                partition.push_back(substring);
                partitionRec(s.substr(i, s.length()), ans, partition);
                // {
                    // return true;
                // }
                partition.pop_back();
            }
        }
        // return false;
        
        
    }
};
