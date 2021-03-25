class Solution {
public:
    static bool cmp(pair<int, char> &p1, pair<int, char> &p2)
    {
        return p1.first > p2.first;
    }
    string reorganizeString(string S) {
        unordered_map<char, int> mp;
        for(int i=0;i<S.length();i++)
        {
            mp[S[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second, it->first});
        }
        queue<pair<int,char>> q;
        string ans = "";
        while(!pq.empty())
        {
            if(pq.size() == 1 && q.empty())
            {
                if(pq.top().first > 1 )
                {
                    return "";
                }
                ans += pq.top().second;
                return ans;
            }
            char ch = pq.top().second;
            int oc = pq.top().first;
            pq.pop();
            oc--;
            cout<<ch<<endl;
            ans += ch;
            if(!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
            if(oc > 0)
            {
                q.push({oc, ch});
            }
        }
        return ans;
    }
};