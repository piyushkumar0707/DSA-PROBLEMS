class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i}; // return indices
            }
            
            mpp[num] = i; // store current number with its index
        }
        return {}; // return empty vector if no solution
    }
};
