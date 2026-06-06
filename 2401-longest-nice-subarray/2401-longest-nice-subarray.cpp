class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits=0, maxLen, left=0;


        for(int right=0; right<nums.size(); right++){
            while((usedBits & nums[right])!=0 ){
                usedBits^=nums[left]--;
                left++;
            }
            usedBits= usedBits|nums[right];
            maxLen= max(maxLen,right-left+1);

        }return maxLen;
        
    }
};