class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_Bound(nums, target), upper_Bound(nums,target)};
        
    }
    int lower_Bound(vector<int> &nums, int target){
        int ans=-1;
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }else if(nums[mid]<target)lo=mid+1;
            else hi=mid-1;
        }return ans;
    }
    int upper_Bound(vector<int> &nums, int target){
        int ans=-1;
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                lo=mid+1;
            }else if(nums[mid]<target)lo=mid+1;
            else hi=mid-1;
        }return ans;
    }
};