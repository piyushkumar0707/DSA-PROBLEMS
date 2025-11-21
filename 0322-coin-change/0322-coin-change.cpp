class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize DP array with large value (amount+1 is safe upper bound)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case

        // Build up the solution
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still larger than amount, it means no solution
        return dp[amount] > amount ? -1 : dp[amount];
    }
};