class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int start=1;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[start-1]){  //for k we can set start-k
                start+=1;
                nums[start]=nums[i];
            }
        }return start+1;
    }
};