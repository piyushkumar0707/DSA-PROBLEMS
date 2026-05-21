class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int>prefix;
        for(int i=0;i<nums.size(); i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }return prefix;
    }
};