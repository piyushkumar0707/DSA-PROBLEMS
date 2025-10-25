class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;
        grid[i][j] = 0; // Mark visited by sinking land
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Flood-fill from boundary land cells
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        // Step 2: Count remaining land cells
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    count++;

        return count;
    }
};