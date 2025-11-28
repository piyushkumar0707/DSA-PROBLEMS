class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        // DP table: (n+1) x (m+1)
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        // Base case: empty string and empty pattern
        dp[0][0] = true;
        
        // Handle patterns with leading '*'
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
        
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};