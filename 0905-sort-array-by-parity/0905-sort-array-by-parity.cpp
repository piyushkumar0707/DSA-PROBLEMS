class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                swap(nums[start],nums[i]);
                start+=1;
            }
        }return nums;
    }
};