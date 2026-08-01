class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(0, -1, nums,dp);
        
    }

    int solve(int i, int prevIndex, vector<int>&nums, vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prevIndex+1]!=-1)return dp[i][prevIndex+1];
        int exclude= solve(i+1, prevIndex, nums,dp);

        int include=0;
        if(prevIndex ==-1 || nums[i]>nums[prevIndex]){
            include= 1+ solve(i+1, i, nums,dp);
        }return dp[i][prevIndex+1]=max(include, exclude);
    }
};


// //int lengthOfLIS(vector<int>& nums) {
//     vector<int> tails;
    
//     for (int num : nums) {
//         int pos = lower_bound(tails.begin(), tails.end(), num) - tails.begin();
        
//         if (pos == tails.size()) {
//             tails.push_back(num);   // num sabse bada hai, naya length banao
//         } else {
//             tails[pos] = num;       // replace karo better (chhoti) ending se
//         }
//     }
    
//     return tails.size();
// }