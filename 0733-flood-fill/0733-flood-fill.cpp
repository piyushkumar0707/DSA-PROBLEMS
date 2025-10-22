class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();

        // Boundary and color check
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor)
            return;

        image[r][c] = color;

        // Explore 4 directions
        dfs(image, r + 1, c, color, originalColor); // Down
        dfs(image, r - 1, c, color, originalColor); // Up
        dfs(image, r, c + 1, color, originalColor); // Right
        dfs(image, r, c - 1, color, originalColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image; // No change needed

        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};