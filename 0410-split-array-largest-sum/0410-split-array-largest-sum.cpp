class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo= *max_element(nums.begin(),nums.end());
        int hi= accumulate(nums.begin(), nums.end(),0);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,mid,k))hi=mid;
            else lo=mid+1;

        }return lo;
        
    }

    int check(vector<int>& nums,int mid, int k){
        int count=1, current=0;
        for(int num: nums){
            if(num+current>mid){
                count++;
                current=0;
            }current+=num;

        }return count<=k;

    }
};