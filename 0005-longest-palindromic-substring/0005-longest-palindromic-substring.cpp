class Solution {
public:


    int start=0;
    int maxLength=0;
    void expandAroundCenter(string &s, int left, int right){
        while(left>=0 && right<=s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        int length=right-left-1;
        
        if(length>maxLength){
            maxLength=length;
            start=left+1;
        }
    }

    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0; i<n; i++){
            expandAroundCenter(s,i,i);
            expandAroundCenter(s,i,i+1);
        }
        return s.substr(start, maxLength);
        
    }
};