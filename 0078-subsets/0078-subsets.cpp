class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        // Helper function for backtracking
        function<void(int)> backtrack = [&](int start) {
            result.push_back(current);  // Add current subset
            for (int i = start; i < nums.size(); ++i) {
                current.push_back(nums[i]);     // Choose
                backtrack(i + 1);               // Explore
                current.pop_back();             // Un-choose
            }
        };

        backtrack(0);
        return result;
    }
};