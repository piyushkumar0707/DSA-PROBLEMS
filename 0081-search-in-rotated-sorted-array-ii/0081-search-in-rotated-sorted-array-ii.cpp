class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(nums[mid]==target)return true;
            if(nums[lo]==nums[mid] & nums[mid]==nums[hi]){
                lo++;
                hi--;
                continue;
            }
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target & target<nums[mid])hi=mid-1;
                else lo=mid+1;
            }else{
                if(nums[hi]>=target &target>nums[mid])lo=mid+1;
                else hi=mid-1;
            }
        }return false;
        
    }
};