class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            // Update histogram heights
            for (int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            // Compute max area for this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Sentinel to flush stack
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        heights.pop_back(); // Remove sentinel
        return maxArea;
    }
};