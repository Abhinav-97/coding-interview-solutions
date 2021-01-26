class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int left = 0;
        int right = 0;
        map<int,int> baskets;
        int ans = 0;
        while(left < tree.size() && right < tree.size()){
            if(baskets.find(tree[right]) == baskets.end() && baskets.size() == 2)
            {
                baskets[tree[left]]--;
                if(baskets[tree[left]] == 0)
                {
                    baskets.erase(tree[left]);
                }
                left++;
            }
            else{
                baskets[tree[right]]++;
                right++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};
