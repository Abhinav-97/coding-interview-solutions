class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = 0;
        if(target == "0000")
        {
            return ans;
        }
        queue<string> q;
        map<string, bool> deadEndsMap;
        for(int i=0;i<deadends.size();i++)
        {
            deadEndsMap[deadends[i]] = true;
        }
        if(deadEndsMap.find(target) != deadEndsMap.end() || deadEndsMap.find("0000") != deadEndsMap.end())
        {
            return -1;
        }
        q.push("0000");
        while(!q.empty())
        {
            int k = q.size();
            ans++;
            while(k--)
            {
                string number = q.front();
                q.pop();
                for(int i=0;i<target.length();i++)
                {
                    string comb = number;
                    string combNeg = number;
                    comb[i] = ((comb[i] - '0' + 1)%10) + '0';
                    if(combNeg[i] == '0')
                    {
                        combNeg[i] = '9';
                    }
                    else{
                        combNeg[i] = ((combNeg[i] - '0' - 1)%10) + '0';
                    }
                    if(comb == target || combNeg == target)
                    {
                        return ans;
                    }
                    if(deadEndsMap.find(comb) == deadEndsMap.end())
                    {
                        deadEndsMap[comb] = true;
                        q.push(comb);
                    }
                    if(deadEndsMap.find(combNeg) == deadEndsMap.end())
                    {
                        deadEndsMap[combNeg] = true;
                        q.push(combNeg);
                    }
                }
            }
        }
        return -1;
    }
};