class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Track the lowest price so far
        int maxProfit = 0;        // Track the maximum profit

        for (int price : prices) {
            // Update minPrice if we find a lower price
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate profit if sold today
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }
};