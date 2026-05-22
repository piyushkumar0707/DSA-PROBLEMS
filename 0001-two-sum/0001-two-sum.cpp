class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0; i<n; i++){
            int num=nums[i];
            int moreNeeded=target-num;
            if(mpp.find(moreNeeded)!=mpp.end()){
                return{mpp[moreNeeded],i};
            }mpp[num]=i;
        }return {-1,-1};
    }
};