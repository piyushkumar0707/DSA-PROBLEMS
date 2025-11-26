class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // empty t can always be formed

        for (int i = 0; i < m; i++) {
            // traverse backwards to avoid overwriting
            for (int j = n; j > 0; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return (int)dp[n];
    }
};