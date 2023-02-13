class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ptr1 = 0, ptr2 = 0;
        int profit = 0, buy = prices[0], sell = prices[0];

        while(ptr2 < prices.size()) {
            if(prices[ptr1] > prices[ptr2]) {
                buy = prices[ptr2];
                ptr1 = ptr2;
                sell = prices[ptr2];
            }
            if(prices[ptr2] > sell) {
                sell = prices[ptr2];
            }
            ptr2++;
            profit = (sell-buy) > profit ? (sell-buy) : profit;
        }
        return profit;
    }
};
