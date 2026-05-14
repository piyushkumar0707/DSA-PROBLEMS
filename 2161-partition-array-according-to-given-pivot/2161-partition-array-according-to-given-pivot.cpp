class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for(int x: nums){
            if(x < pivot)less.push_back(x);
            else if(x== pivot) equal.push_back(x);
            else{
                greater.push_back(x);
            }
        }vector<int>result;
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};