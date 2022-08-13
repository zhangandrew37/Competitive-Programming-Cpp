class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        int r = 1;
        while (r < prices.size()){
            if (prices[l] < prices[r]){
                profit = max(profit, prices[r]-prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        
        return profit;
    }
};

/*
Given: an array of prices (which are integers)
- ith element represents price of stock on ith day

Goal: maximize profit
- choose a day to buy a stock
- choose a day in the future to sell it (must be FUTURE)

Specification:
- no negative numbers
*/