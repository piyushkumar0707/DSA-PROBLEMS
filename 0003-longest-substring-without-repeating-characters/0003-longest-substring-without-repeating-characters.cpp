class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int left=0; int best=0;
        for(int right=0; right<s.size(); right++){
            freq[s[right]]++;

            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            best= max(best, right-left+1);
        }return best;
      


        
    }
};