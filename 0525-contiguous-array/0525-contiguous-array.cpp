class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>firstIndex;
        firstIndex[0]=-1;
        int sum=0, maxLen=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0?-1:1);
            if(firstIndex.find(sum)!=firstIndex.end()){
                 maxLen=max(maxLen,i-firstIndex[sum]);
            }else{
                firstIndex[sum]=i;
            }
                
            
        }return maxLen;
    }
};