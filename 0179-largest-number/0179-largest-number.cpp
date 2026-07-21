class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>strs;
        for(int i=0; i<nums.size(); i++){
            strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(), strs.end(), [](string a, string b){
            return (a+b)>(b+a);

        });
        
        string result="";
        for(int i=0; i<strs.size(); i++){
            result+=strs[i];
        }
        if(result[0]=='0')return "0";
        return result;

    }
};