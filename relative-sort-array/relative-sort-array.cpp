class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }
        
        for(int i=0;i<arr2.size();i++)
        {
            cout<<mp[arr2[i]];
            for(int j=0;j<mp[arr2[i]];j++)
            {
                cout<<arr2[i];
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            for(int i=0;i<it->second;++i)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
        
        
    }
};