class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0];  // If we buy on day 0
        int cash = 0;           // No stock on day 0

        for (int i = 1; i < n; i++) {
            hold = max(hold, cash - prices[i]);             // Buy or keep holding
            cash = max(cash, hold + prices[i] - fee);       // Sell or keep cash
        }

        return cash;
    }
};