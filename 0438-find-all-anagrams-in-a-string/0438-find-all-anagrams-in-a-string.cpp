class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        if(s.size()<p.size())return result;
        int k=p.size();
        vector<int>patFreq(26,0), winFreq(26,0);
        for(char c:p)patFreq[c-'a']++;
        for(int i=0; i<k; i++)winFreq[s[i]-'a']++;
        if(winFreq==patFreq)result.push_back(0);
        for(int i=k; i<s.size(); i++){
            winFreq[s[i]-'a']++;
            winFreq[s[i-k]-'a']--;
            if(winFreq==patFreq)result.push_back(i-k+1);
        }return result;
    }
};