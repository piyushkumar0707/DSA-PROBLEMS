class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums, k-1);
        
    }
    int atMost(vector<int>&nums,int k){
        int left=0, count =0;
        unordered_map<int,int>freq;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0)freq.erase(nums[left]);
                left++;}
                count+=right-left+1;
            
        }return count;
    }
};