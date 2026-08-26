class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>even, odd;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }else{odd.push_back(nums[i]);}
        }
        // concatenate result
        vector<int>result;
        result.insert(result.end(), even.begin(), even.end());
        result.insert(result.end(),odd.begin(), odd.end());
        return result;
    }
};