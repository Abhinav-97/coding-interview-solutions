class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(k - nums[i]) != mp.end())
            {
                ans++;
                mp[k-nums[i]]--;
                if(mp[k-nums[i]] == 0)
                {
                    
                    mp.erase(k-nums[i]);
                }
            }
            else{
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};
