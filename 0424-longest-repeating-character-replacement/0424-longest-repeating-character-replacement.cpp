class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0};
        int maxLen=0;
        int left=0;
        for(int right=0; right<s.size(); right++){
            freq[s[right]-'A']++;
            int maxfreq=max(maxfreq , freq[s[right]-'A']);
            while(right-left+1-maxfreq>k){
                freq[s[left]-'A']--;
                left++;
                maxfreq=*max_element(freq, freq+26);
            }maxLen= max(maxLen, right-left+1);
        }return maxLen;
    }
};