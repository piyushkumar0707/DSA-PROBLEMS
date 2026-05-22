class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num: nums){
           
            if(mpp.find(num)!=mpp.end())return true;//duplicate found
            mpp[num]=1;//mark as seen
        }return false;
    }
};