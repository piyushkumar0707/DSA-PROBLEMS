class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1; // Base case: zero odd numbers seen
        int oddCount = 0, result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            result += count[oddCount - k];
            count[oddCount]++;
        }

        return result;
    }
};