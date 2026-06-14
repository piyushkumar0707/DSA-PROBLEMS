class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        while(lo<hi){
            int mid= lo+(hi-lo)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1])lo=mid+2;
                else hi=mid;
            }else{
                if(nums[mid]==nums[mid-1])lo=mid+1;
                else hi=mid;
            }
        }return nums[lo];

        
    }
};