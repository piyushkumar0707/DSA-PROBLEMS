class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash+256, -1);
        int n=s.size();
        int left=0, maxlen=0;
        for(int right=0; right< n; right++){
            char ch= s[right];
        if(hash[ch]!=-1 && hash[ch]>=left){
            left= hash[ch]+1;
        }hash[ch]= right;
        maxlen = max(maxlen, right-left+1);
    }return maxlen;}
};