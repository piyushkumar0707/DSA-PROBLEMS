class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int>freq;
        for(char c:s)freq[c]++;
        for(char c:t){
            if(freq.find(c)==freq.end())return false;
            freq[c]--;
            if(freq[c]<0)return false;

        }return true;
    }
};