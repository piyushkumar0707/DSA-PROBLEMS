class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i=0; i<s.size(); i++){
            last[s[i]]=i; //last char index sabhi ka store ho jayega

        }

        vector<int>result;
        int start=0, end=0;
        for(int i=0; i<s.size(); i++){
            end= max(end, last[s[i]]); //window extend karo

            if(i==end){ //partition
                result.push_back(end-start+1);
                start= i+1; //next partition starts
            }
        }return result;
    }
};