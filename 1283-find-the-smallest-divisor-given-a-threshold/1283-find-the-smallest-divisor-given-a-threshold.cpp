class Solution {
public:
    int sumByD(vector<int> &nums, int div){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= (nums[i]+div-1)/div;
        }return sum;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=0;
        int low=1;
        int high= *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumByD( nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return ans;
    }
};