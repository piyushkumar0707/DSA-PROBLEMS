class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int winSum=0;
        int maxSum=0;
        for(int i=0; i<k; i++){
            maxSum+=nums[i];
        } winSum=maxSum;
        for(int i=k; i<n; i++){
            maxSum+=nums[i];
            maxSum-=nums[i-k];
            winSum= max(winSum, maxSum);

        }
        return(double)winSum/k;
    }
};