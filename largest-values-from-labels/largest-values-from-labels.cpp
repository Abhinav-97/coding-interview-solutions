class Solution {
public:
    struct Item{
        int value;
        int label;        
    };
    static bool comparator(Item i1, Item i2)
    {
        return i1.value > i2.value;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<Item> items;
        for(int i=0;i<values.size();i++)
        {
            Item item;
            item.value = values[i];
            item.label = labels[i];
            items.push_back(item);
        }
        sort(items.begin(), items.end(), comparator);
        map<int, int> labelsMap;
        int ans = 0;
        for(int i=0;i<items.size();i++)
        {
             if(num_wanted == 0)
             {
                 break;
             }
            if(labelsMap[items[i].label] < use_limit)
            {
                ans += items[i].value;
                num_wanted--;
                labelsMap[items[i].label]++;
            }
        }
        return ans;
    }
};
