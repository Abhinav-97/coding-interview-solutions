class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -1*prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            cash = max(cash, hold+prices[i]-fee); // buy stock
            hold = max(hold, cash-prices[i]); // hold that stock
        }
        return cash;
    }
};