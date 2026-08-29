class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq1;
        for(int i=0; i<nums1.size(); i++){
            freq1[nums1[i]]++;
        }unordered_map<int, int>freq2;
        for(int i=0; i<nums2.size(); i++){
            freq2[nums2[i]]++;
        }

        vector<int>result;
        for(auto it: freq1){
            if(freq2.find(it.first)!=freq1.end()){
                result.push_back(it.first);
            }
        }return result;
    }
};