class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0)
        {
            return false;
        }
        map<int, int> mp;
        for(int i=0;i<hand.size();i++)
        {
            mp[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        int subSetsize = hand.size()/W;
        for(int i=0;i<hand.size();i++)
        {
            auto it = mp.find(hand[i]);
            if(it->second == 0)
            {
                it++;
                continue;
            }
            int previousNum = it->first;
            int k = 0;
            while(k < W-1)
            {
                
                auto itr = mp.find(previousNum+1);
                if(itr == mp.end() || itr->second == 0)
                {
                    return false;
                }
                else{
                    itr->second--;
                }
                previousNum += 1;
                k++;
            }
            it->second--;
            
            it++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};
