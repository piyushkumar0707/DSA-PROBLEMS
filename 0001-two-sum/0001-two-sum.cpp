class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++){
            int sum=target-nums[i];
            if(mpp.find(sum)!=mpp.end()){
                return {mpp[sum],i};
            }mpp[nums[i]]=i;

        }return {};
        
    }
};