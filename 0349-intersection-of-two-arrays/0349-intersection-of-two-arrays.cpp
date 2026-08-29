class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        for(int i:nums1){
            for(int j: nums2){
                if(i==j){
                    s.insert(i);
                }
            }
        }
        vector<int>arr(s.begin(),s.end());
        return arr;
    }
};