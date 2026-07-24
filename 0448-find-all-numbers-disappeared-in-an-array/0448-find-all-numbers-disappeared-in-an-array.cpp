class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();

    // Mark visited numbers
    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]) - 1;
        if (nums[val] > 0) {
            nums[val] = -nums[val];
        }
    }

    // Collect missing numbers
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    return result;
}
};