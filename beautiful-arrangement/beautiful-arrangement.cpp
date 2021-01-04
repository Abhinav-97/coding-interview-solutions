class Solution {
public:
    void helper(int n, bool visited[], vector<int> &vec, int &ans)
    {
        if(vec.size() == n)
        {
            ans++;
            return;
        }
        int pos = vec.size()+1;
        for(int i=1;i<=n;i++)
        {
            if((pos%i == 0 || i%pos == 0) && !visited[i])
            {
                visited[i] = true;
                vec.push_back(i);
                helper(n, visited, vec, ans);
                vec.pop_back();
                visited[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        bool visited[n+1];
        memset(visited, false, sizeof(visited));
        vector<int> vec;
        int ans = 0;
        helper(n, visited, vec, ans);
        return ans;
    }
};
