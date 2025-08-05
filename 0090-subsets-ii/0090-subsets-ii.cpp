class Solution {
public:
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);  // Add current subset to the answer
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;  // Skip duplicates
            ds.push_back(nums[i]);  // Include current element
            findSubsets(i + 1, nums, ds, ans);  // Recurse
            ds.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};