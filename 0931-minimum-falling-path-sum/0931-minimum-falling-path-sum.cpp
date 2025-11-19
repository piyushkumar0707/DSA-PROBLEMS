class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int left = j > 0 ? matrix[i-1][j-1] : INT_MAX;
                int up = matrix[i-1][j];
                int right = j < n-1 ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] += min({left, up, right});
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};