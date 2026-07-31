class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>prefixCount;
        int sum=0, count=0;
        prefixCount[0]=1;
        for(int num:nums){
            sum+=num;
            if(prefixCount.find(sum-k)!=prefixCount.end()){
                count+=prefixCount[sum-k];

            }prefixCount[sum]++;

        }return count;

        
    }
};