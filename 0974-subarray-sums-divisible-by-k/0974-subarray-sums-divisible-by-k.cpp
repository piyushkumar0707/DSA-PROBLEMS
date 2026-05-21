class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>prefixCount;
       prefixCount[0]=1;
       int sum=0, count=0;
       for(int num:nums){
        sum+=num;
        int rem=((sum%k)+k)%k;
        if(prefixCount.find(rem)!=prefixCount.end()){
        count+=prefixCount[rem];
       } prefixCount[rem]++;}
       return count;
    }
};