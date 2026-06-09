class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                first = i;
                break;  // pehla mila, ruk jao
            }
        }
        for(int j = nums.size()-1; j >= 0; j--) {
            if(nums[j] == target) {
                last = j;
                break;  // aakhri mila, ruk jao
            }
        }
        return {first, last};
    }
};