class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0; //no of jumps taken
        int curEnd=0; //current idex we can go
        int maxReach=0; //max index we can go from next indexes
        for(int i=0; i<nums.size()-1; i++){
            maxReach=max(maxReach, i+ nums[i]);
            if(i==curEnd){
                jumps++;
                curEnd=maxReach;
            }
        }
        return jumps;
    }
};