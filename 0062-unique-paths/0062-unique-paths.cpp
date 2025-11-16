class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use long long to avoid overflow
        long long res = 1;
        int total = m + n - 2;
        int k = min(m - 1, n - 1); // Choose the smaller to optimize

        for (int i = 1; i <= k; ++i) {
            res = res * (total - k + i) / i;
        }

        return (int)res;
    }
};