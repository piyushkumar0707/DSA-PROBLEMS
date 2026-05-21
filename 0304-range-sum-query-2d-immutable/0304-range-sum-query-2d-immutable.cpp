class NumMatrix {
private:
    vector<vector<int>> prefix; // 2D prefix sum

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefix = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        // Build prefix sum
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i-1][j-1] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // shift indices by +1 because prefix has extra row/col
        row1++; col1++; row2++; col2++;
        return prefix[row2][col2] 
             - prefix[row1-1][col2] 
             - prefix[row2][col1-1] 
             + prefix[row1-1][col1-1];
    }
};
